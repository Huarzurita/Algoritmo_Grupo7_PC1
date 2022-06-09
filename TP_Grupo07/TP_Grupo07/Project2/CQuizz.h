#pragma once
#include "Capp.h"
template<class Generic>
class Quizz {
private:
	fstream archivoQuizz;
	Generic answer, question;
public:
	Quizz(Generic question, Generic answer ):answer(answer),question(question) {
		archivoQuizz.open("Quizz.txt", ios::app);
	}
	void Save() {
		archivoQuizz << "--------------------------------------------------------------------------------------------" << "\n";
		archivoQuizz << "                                           °QUIZZ°                                          " << "\n";
		archivoQuizz << "--------------------------------------------------------------------------------------------" << "\n";
		archivoQuizz << "    Pregunta: " << question << endl;
		archivoQuizz << "    Respuesta: " << answer << endl;
		archivoQuizz << "--------------------------------------------------------------------------------------------" << endl;
		archivoQuizz << "\n";
	}

	void Print() {
		system("cls");
		cout << "\t APRENDE CON DIVERSIÓN! :D : " << endl;
		cout << "\t QUIZZ: " << "\n";
		cout << "\t Pregunta: " << question << endl;
		cout << "\t "; system("pause");
		cout << "\t Respuesta: " << answer << endl;
		cout << "\t "; system("pause");
	}
};