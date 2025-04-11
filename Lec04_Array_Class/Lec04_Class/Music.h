#pragma once
#include <iostream>  // input, output ���� ���̺귯��
#include <string>   // ���ڿ�
#include <vector>  // STL vector

// Namespace
using namespace std;

class Music {

	// std::vector<float> abd;   // std :: �����ϱ� ���� namespace ���

private:
	string title;
	string artist;
	string album;

	int year;

public:

	// ������
	Music(string title, string artist, string album, int year) {
		this->title = title;         // ��ü �� title
		this->artist = artist;		// ��ü �� artist
		this->album = album;		// ��ü �� album
		this->year = year;			// ��ü �� year
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

	//������
	MusicStreamingService(string service_name) {
		this->service_name = service_name;
	}
	// ���� �߰� ���
	void addMusic(string title, string artist, string album, int year) {
		Music new_music (title, artist, album, year);
		music_list.push_back(new_music);
		cout << title << " by " << artist << " added to " << service_name << endl;
	}

	// ���� ã���ִ� ����(Title)
	Music* searchByTitle(string title) {                     // * �ǹ�: ������ / �����Ͷ�? �ּҰ��� �����ϴ� ���� -> �Լ��� �ּҰ� ��ȯ
		for (int i = 0; i < music_list.size(); i++) {
			if (music_list[i].getTitle() == title) {
				return &music_list[i];                      // = music_list + i   =  & �ǹ�: music_list[i]�� �ּ� -> �迭�� ���� �ƴ� �ּҸ� ��ȯ����� ��.(call by reference)
			}
		}
		return NULL;
	}

	// ���� ã���ִ� ����(Artist)
};