#include <bits/stdc++.h>

using namespace std;

#define MAX_PLAYLIST_SIZE 4 //Keeping it small just for testing purpose.
#define TRUE 1
#define FALSE 0


typedef struct node
{
	char song;
	struct node *next;
	struct node *prev;
}node;

typedef struct Queue
{
	node * front;
	node * tail;
	int CurrentPlayListSize; //Keep track of number of songs

}Queue;

unordered_map<int, node*> umap;

// This is one time event
void initializeQueue(Queue **q)
{
	*q  = (Queue *)malloc(sizeof(Queue));
	if(*q != NULL)
	{
		(*q)->front = NULL;
		(*q)->tail = NULL;
		(*q)->CurrentPlayListSize =0;
	}   
}   
// Return TRUE if play list is empty 
int isEmpty(Queue *q)
{
	if( q->front == NULL && q->tail == NULL)
		return true;

	return false;
}

void InsertSong(Queue *q, char song)
{
	node *newNode = (node *) malloc(sizeof(node));
	if(newNode != NULL)
	{
		newNode->song = song;
		newNode->next = NULL;
		newNode->prev = q->tail;
		if(q->tail)
		{
			q->tail->next = newNode;
		}
		q->tail = newNode;
		if(!(q->front))
			q->front = newNode;
		umap[song] = newNode;
		q->CurrentPlayListSize++;
	}
	return ;
}

int DeleteSong(Queue *d){

	if(isEmpty(d) == TRUE)
	{
		printf("\n Play list is empty");
		return -1;
	}

	node *q  = d->front;
	d->front = q->next;

	if(q->next)
		q->next->prev = NULL;
	else
		d->tail = NULL;

	int song = q->song;
	free(q);
	d->CurrentPlayListSize--;

	return song;
}

// This function modifies play list when song is present in play list
void updatePlayList(Queue *d, char song)
{
	if(d->front == umap[song]) // If the song is at the front of play list. 
	{
		DeleteSong(d);
		InsertSong(d, song);
	}
	else if(d->tail == umap[song]) // If it is last in play list, mothing to do. 
	{
		return;
	}
	else
	{
		// Update the pointer
		node * q = umap[song];
		q->prev->next =  q->next;
		q->next->prev = q->prev;
		q->prev = d->tail;

		d->tail->next = q;
		d->tail  = q;
		q->next = NULL;
	}
}

void printCurrentData( Queue *d)
{
	node *current = d->front; 
	for(int i=0; i<= d->CurrentPlayListSize && current; i++)
	{
		printf("%c ", current->song);
		current  = current->next;
	}
}

void ArrangeSongs(Queue *d, char song)
{
	//CASE: Song is not present in play list and play list is not FULL yet
	if (umap.find(song) == umap.end() && d->CurrentPlayListSize < MAX_PLAYLIST_SIZE)
	{
		InsertSong(d, song);
	}

	//CASE: song is not present in play list and play list is full.
	if(umap.find(song) == umap.end() && d->CurrentPlayListSize == MAX_PLAYLIST_SIZE)
	{
		char last = DeleteSong(d);
		umap.erase(last);
		
		InsertSong(d, song);
	}

	//Song is present in play list
	if(umap.find(song) != umap.end())
	{
		updatePlayList(d, song);
	}

	printf("\nPlaylist Songs: ");
	printCurrentData(d);
}
int main()
{
	Queue *d;
	initializeQueue(&d);

	char songs[] = {'A', 'B', 'C', 'A', 'C', 'X', 'C', 'Y', 'Z', 'A'}; //Assuming each charcter represent a song.
	int i = 0;
	int NumberOfPlayedSongs = sizeof(songs)/sizeof(songs[0]);

	while(i < NumberOfPlayedSongs)
	{
		printf("\nPlayed Song : %c " , songs[i]);
		ArrangeSongs(d, songs[i]);
		printf("\n");
		i++;
	}
	printf("\n");
	return 0;
}
