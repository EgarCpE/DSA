#ifndef Circular_LL_H
#define Circular_LL_H

#include <iostream>
#include <string>

template <typename T> //stores any type of data
class SingleSongNode {
public:
    T SongTitle;
    SingleSongNode<T>* next = nullptr;
    SingleSongNode<T>* prev = nullptr;

    // add new song to the playlist 
    SingleSongNode(T title) { 
        SongTitle = title; //saves the song title
        next = nullptr; // points next to null 
        prev = nullptr; 

    }

};

template <typename T>
void addSong(T newTitle, SingleSongNode<T> *& PlayListHead) {

    SongNode<T>* newNode = new SingleSongNode<T>(newsongTitle);

// this checks if the playlist is empty, then the new song will point to itself 
    if (PlayListHead == nullptr) {
        PlayListHead = newNode;
        PlayListHead->next = PlayListHead;
        PlayListHead->prev = PlayListHead;
        std::cout << "Add initial song: " << newTitle << "\n";
        return;
    }
 
}

// next song
 template <typename T> //setter for data type| you can assign any kind of data type 
 void NextSong(SingleSongNode<T> *& PlayListHead) { // gets the data of the address  
    if (PlayListHead == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }
    PlayListHead = PlayListHead->next; //responsible for moving to the next song in the playlist
    std::cout << "Now playing: " << PlayListHead->SongTitle << "\n";

}

// prev song | same function as next song but it moves to the previous song in the playlist
template <typename T>
void PrevSong(SingleSongNode<T> *& PlayListHead) {
    if (PlayListHead == nullptr) {
        std::cout << "Playlist is empty.\n";
        return; 
    }
    PlayListHead = PlayListHead->prev; //responsible for moving to the previous song in the playlist
    std::cout << "Now playing: " << PlayListHead->SongTitle << "\n";
}

// play all
template <typename T>
void PlayAll(SingleSongNode<T> *& PlayListHead) { //gets the data of the address
    if (PlayListHead == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }
    SingleSongNode<T>* current = PlayListHead;
    do {
        std::cout << "Now playing: " << current->SongTitle << "\n";
        current = current->next;
    } while (current != PlayListHead);
}
// delete song
template <typename T>
void DeleteSong(T title, SingleSongNode<T> *& PlayListHead) {
    if (PlayListHead == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }
    SingleSongNode<T>* current = PlayListHead; //creates a pointer for the head of the playlist and traverse each node to find songs
    do {
        if (current->SongTitle == title) { // checks the current nodes title to determine whether this will be deleted or not
            if (current->next == current) { //only one song in the playlist 
                delete current;
                PlayListHead = nullptr;
                std::cout << "Deleted song: " << title << "\n";
                return;
            }
            current->prev->next = current->next; //removes the song from the playlist
            current->next->prev = current->prev;
            if (current == PlayListHead) {
                PlayListHead = current->next; //moves to the next song in the playlist
            }
        }
 
#endif