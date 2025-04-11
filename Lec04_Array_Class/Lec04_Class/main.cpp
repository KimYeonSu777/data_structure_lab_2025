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
	my_service.addMusic("PolaroidLove", "ENHYPEN ", "DIMENSION ", 2022);
	my_service.addMusic("Ditto", "NewJeans ", "ALBUM ", 2023);
	my_service.addMusic("CAKE", "ITZY ", "ALBUM ", 2023);
	my_service.addMusic("SundayMorning", "Maroon5 ", "ALBUM ", 2024);

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

	return 0;
}