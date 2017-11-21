PlayList.cpp contains code to maintain 'N' most recently played songs.

Test Case: {'A', 'B', 'C', 'A', 'C', 'X', 'C', 'Y', 'Z', 'A'}
Where each character represent a song. 

vinod@vinod-Latitude-3480:~$ g++ -std=c++11 playList.cpp -o playList //Compilation

vinod@vinod-Latitude-3480:~$ ./playList //Run
Played Song : A 
Playlist Songs: A 

Played Song : B 
Playlist Songs: A B 

Played Song : C 
Playlist Songs: A B C 

Played Song : A 
Playlist Songs: B C A 

Played Song : C 
Playlist Songs: B A C 

Played Song : X 
Playlist Songs: B A C X 

Played Song : C 
Playlist Songs: B A X C 

Played Song : Y 
Playlist Songs: A X C Y 

Played Song : Z 
Playlist Songs: X C Y Z 

Played Song : A 
Playlist Songs: C Y Z A 

vinod@vinod-Latitude-3480:~$ 



