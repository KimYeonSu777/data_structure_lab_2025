#include "Complex.h"
// #include "Car.h"          // SportsCar.h 안에 Car.h 가 있기 때문에 생략해도 OK
#include "SportsCar.h"
#include "Music.h"

int main() {

	/*
	Complex a, b, c;

	a.read("A= ");
	b.read("B= ");
	c.add(a, b);
	a.print("A= ");
	b.print("B= ");
	c.print("A+B= ");
	*/

	/*
	Car myCar;
	Car momsCar(10, "K5", 2);
	Car mySecondCar;

	myCar.whereAmI();
	momsCar.whereAmI();
	momsCar.changeGear(3);
	momsCar.speedUp();
	momsCar.display();

	mySecondCar.speedUp();
	


	Music myMusic("");
	*/


	// music streaming service를 생성
	MusicStreamingService my_service("spotify");

	// add music to music streaming service

	my_service.addMusic("PolaroidLove", "ENHYPEN", "DIMENSION", 2022);
	my_service.addMusic("Ditto", "NewJeans", "ALBUM", 2023);
	my_service.addMusic("Attention", "NewJeans", "ALBUM", 2023);
	my_service.addMusic("CAKE", "ITZY ", "ALBUM", 2023);
	my_service.addMusic("SundayMorning", "Maroon5", "ALBUM", 2024);
	my_service.addMusic("sugar", "Maroon5", "ALBUM", 2015);

	//  add by user 직접 해보기-------------------------------------------------------------------------!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// music 객체 선언 -> 사용자 입력받기 (cin 사용)
	// 입력받은 값을 선언한 music객체 멤버변수를 하나씩 채우기
	// 마지막으로 music객체 my_service의 music_list에 push_back()


	// search music by title
	string music_title;
	cout << "Enter the Music Title: ";
	cin >> music_title;
	Music* result = my_service.searchByTitle(music_title);
	
	if (result != NULL) {
		cout << "Found: " << result->getTitle() << " by " << result->getArtist() << endl;   // endl 은 엔터쳐주는 역할
	}
	else {
		cout << "not Found" << endl;
	}

	// search music by artist
	string artist_name;
	cout << "Enter the Artist Name";
	cin >> artist_name;
	vector<Music*> artist_result = my_service.searchByAltist(artist_name);
	
	if (artist_result.size() > 0) {
		cout << "Found " << artist_result.size() << "songs by " << artist_name << " : " << endl;

		for (int i = 0; i < artist_result.size(); i++) {
			cout << artist_result[i]->getTitle() << endl;
		}
	}
	else {
		cout << "Not found" << endl;
	}

	return 0;
}