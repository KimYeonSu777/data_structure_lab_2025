#pragma once
#include <iostream>  // input, output 관련 라이브러리
#include <string>   // 문자열
#include <vector>  // STL vector

// Namespace
using namespace std;

class Music {

	// std::vector<float> abd;   // std :: 생략하기 위해 namespace 사용

private:
	string title;
	string artist;
	string album;

	int year;

public:

	// 생성자
	Music(string title, string artist, string album, int year) {
		this->title = title;         // 객체 안 title
		this->artist = artist;		// 객체 안 artist
		this->album = album;		// 객체 안 album
		this->year = year;			// 객체 안 year
	}

	// Getters
	string getTitle() {
		return title;
	}

	string getArtist() {
		return artist;
	}

	string getAlbum() {
		return album;
	}

	int getYear() { 
		return year;
	}

};


class MusicStreamingService {


private:

	string service_name;
	vector<Music> music_list;

public:

	//생성자
	MusicStreamingService(string service_name) {
		this->service_name = service_name;
	}
	// 음악 추가 기능
	void addMusic(string title, string artist, string album, int year) {
		Music new_music (title, artist, album, year);
		music_list.push_back(new_music);
		cout << title << " by " << artist << " added to " << service_name << endl;
	}

	// 음악 찾아주는 서비스(Title)
	Music* searchByTitle(string title) {                     // * 의미: 포인터 / 포인터란? 주소값을 저장하는 변수 -> 함수는 주소값 반환
		for (int i = 0; i < music_list.size(); i++) {
			if (music_list[i].getTitle() == title) {
				return &music_list[i];                      // = music_list + i   =  & 의미: music_list[i]의 주소 -> 배열은 값이 아닌 주소를 반환해줘야 함.(call by reference)
			}
		}
		return NULL;
	}

	// 음악 찾아주는 서비스(Artist)
};