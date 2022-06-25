#include "Controller.h"
using namespace System;
using namespace std;

void creadores() {
	Console::ForegroundColor = ConsoleColor::Magenta;
	Console::SetCursorPosition(12, 9);
	cout << "|--------------------------------------------------------------------------------------------|";
	Console::SetCursorPosition(12, 10);
	cout << "|                                      °ORGANIZE YOU°                                        |";
	Console::SetCursorPosition(12, 11);
	cout << "|--------------------------------------------------------------------------------------------|";
	Console::SetCursorPosition(12, 12);
	cout << "|  CREADO POR:                                                                               |";
	Console::SetCursorPosition(12, 13);
	cout << "| " << char(16) << " André Alonso Arroyo Ormeño                                                               |";
	Console::SetCursorPosition(12, 14);
	cout << "| " << char(16) << " Jessica Elizabeth Comettant Rubiños                                                      |";
	Console::SetCursorPosition(12, 15);
	cout << "| " << char(16) << " Miguel Alejandro Daniel Huarcaya Chavez                                                  |";
	Console::SetCursorPosition(12, 16);
	cout << "|--------------------------------------------------------------------------------------------|";
	_getch();
	system("cls");
}
auto primer_menu = []()->void {
	Console::ForegroundColor = ConsoleColor::Cyan;
	cout << "\t|--------------------------------------------------------------------------------------------|"<<endl;
	cout << "\t|                                          °MENÚ°                                            |"<<endl;
	cout << "\t|--------------------------------------------------------------------------------------------|"<<endl;
	cout << "\t| 1. Agregar Tarea                                                                           |"<<endl;
	cout << "\t| 2. Agregar Evento                                                                          |"<<endl;
	cout << "\t| 3. Agregar Recordatorio                                                                    |"<<endl;
	cout << "\t| 4. Agregar Nota                                                                            |"<<endl;
	cout << "\t| 5. Agregar Contacto                                                                        |"<<endl;
	cout << "\t| 6. Agregar Musica                                                                          |"<<endl;
	cout << "\t| 7. Agregar Horario                                                                         |"<<endl;
	cout << "\t| 8. Mostrar Datos                                                                           |"<<endl;
	cout << "\t| 9. Simulación de Usuarios                                                                  |" << endl;
	cout << "\t| 10.Usuarios en hash table                                                                  |" << endl;
	cout << "\t| 11.QUIZZ :D                                                                                |"<<endl;
	cout << "\t| 12.Bye bye                                                                                 |"<<endl;
	cout << "\t|--------------------------------------------------------------------------------------------|" << endl;
};
function<void()> segundo_menu = []() {
	Console::ForegroundColor = ConsoleColor::Cyan;
	cout << "\t|--------------------------------------------------------------------------------------------|"<<endl;
	cout << "\t|                                          °MENÚ°                                            |"<<endl;
	cout << "\t|--------------------------------------------------------------------------------------------|"<<endl;
	cout << "\t| 1. Mostrar Tareas                                                                          |"<<endl;
	cout << "\t| 2. Mostrar Eventos                                                                         |"<<endl;
	cout << "\t| 3. Mostrar Recordatorios                                                                   |"<<endl;
	cout << "\t| 4. Mostrar Notas                                                                           |"<<endl;
	cout << "\t| 5. Mostrar Contactos                                                                       |"<<endl;
	cout << "\t| 6. Mostrar Canciones                                                                       |"<<endl;
	cout << "\t| 7. Mostrar Horario                                                                         |"<<endl;
	cout << "\t| 8. Bye bye                                                                                 |"<<endl;
	cout << "\t|--------------------------------------------------------------------------------------------|" << endl;
};
void imprimir(function<void()>funcion) {
	funcion();
}


int main() {
	setlocale(LC_ALL, "esp");
	Controller* controller = new Controller();
	int opc, opc2, opc3,horita; long telefono;
	string a, titulo, fecha, hora, urgencia, completado, 
	lugar, descripcion, correo, cancion, genero, artista, actividad, horaI, horaF, contacto; 
	imprimir(creadores);
	while (true) {
		do {
			system("cls");
			imprimir(primer_menu);
			cout << "\n\t    Ingresar opción:"; cin >> opc;
		} while (opc < 1 || opc>13);
		system("cls");
		switch (opc) {
		case 1:
			Console::ForegroundColor = ConsoleColor::Gray;
			cout << "\t INGRESE LOS DATOS SOLICITADOS" << endl; getline(cin, a);
			cout << "\t  Ingresar título de la tarea: "; getline(cin, titulo);
			cout << "\t  Ingresar fecha de la tarea: "; getline(cin, fecha);
			cout << "\t  Ingresar hora de la tarea: "; cin >> horita;
			cout << "\t  Ingresar urgencia de la tarea: "; cin >> urgencia;
			do
			{
				cout << "\t  Ingresar si la tarea ha sido completada (SI(S) o NO(N)): "; cin >> completado;
			} while (completado != "S" && completado != "N");
			controller->addTarea(completado, titulo, fecha, horita, urgencia);
			controller->guardarTareas();
			_getch();
			break;
		case 2:
			Console::ForegroundColor = ConsoleColor::Gray;
			cout << "\t INGRESE LOS DATOS SOLICITADOS" << endl; getline(cin, a);
			cout << "\t  Ingresar título del evento: "; getline(cin, titulo);
			cout << "\t  Ingresar fecha del evento: "; getline(cin, fecha);
			cout << "\t  Ingresar hora del evento: "; getline(cin, hora);
			cout << "\t  Ingresar lugar del evento: "; getline(cin, lugar);
			cout << "\t  Ingresar urgencia del evento: "; getline(cin, urgencia);
			cout << "\t  Ingresar descripción del evento: "; getline(cin, descripcion);
			controller->addEvento(lugar, titulo, fecha, hora, descripcion, urgencia);
			controller->guardarEventos();
			_getch();
			break;
		case 3:
			Console::ForegroundColor = ConsoleColor::Gray;
			cout << "\t INGRESE LOS DATOS SOLICITADOS" << endl; getline(cin, a);
			cout << "\t  Ingresar título del recordatorio: "; getline(cin, titulo);
			cout << "\t  Ingresar fecha del recordatorio: "; getline(cin, fecha);
			cout << "\t  Ingresar hora del recordatorio: "; getline(cin, hora);
			cout << "\t  Ingresar urgencia del recordatorio: "; getline(cin, urgencia);
			controller->addRecordatorio(titulo, fecha, hora, urgencia);
			controller->guardarRecordatorios();
			_getch();
			break;
		case 4:
			Console::ForegroundColor = ConsoleColor::Gray;
			cout << "\t INGRESE LOS DATOS SOLICITADOS" << endl; getline(cin, a);
			cout << "\t  Ingresar título de la nota: "; getline(cin, titulo);
			cout << "\t  Ingresar descripción de la nota: "; getline(cin, descripcion);
			controller->addNota(titulo, descripcion);
			controller->guardarNotas();
			_getch();
			break;
		case 5:
			Console::ForegroundColor = ConsoleColor::Gray;
			cout << "\t INGRESE LOS DATOS SOLICITADOS" << endl; getline(cin, a);
			cout << "\t  Ingresar nombre del contacto: "; getline(cin, contacto);
			cout << "\t  Ingresar correo del contacto: "; getline(cin, correo);
			cout << "\t  Ingresar teléfono del contacto: "; cin >> telefono;
			controller->add_Agenda(telefono, correo, contacto);
			controller->guardar_Agenda();
			_getch();
			break;
		case 6:
			Console::ForegroundColor = ConsoleColor::Gray;
			cout << "\t INGRESE LOS DATOS SOLICITADOS: " << endl; getline(cin, a);
			cout << "\t  Ingresar nombre de la canción: "; getline(cin, cancion);
			cout << "\t  Ingresar género de la canción: "; getline(cin, genero);
			cout << "\t  Ingresar artista de la canción: "; getline(cin, artista);
			controller->add_Musica(cancion, genero, artista);
			_getch();
			break;
		case 7:
			cout << "\t INGRESE LOS DATOS SOLICITADOS: " << endl; getline(cin, a);
			cout << "\t  Ingrese el nombre de la actividad: "; getline(cin, actividad);
			cout << "\t  Ingrese la hora inicial: "; getline(cin, horaI);
			cout << "\t  Ingrese la hora final: "; getline(cin, horaF);
			controller->add_Horario(actividad, horaI, horaF);
			_getch();
			break;
		case 8:
			do {
				system("cls");
				imprimir(segundo_menu);
				cout << "\n\t    Ingresar opción:"; cin >> opc2;
			} while (opc2 < 1 || opc>8);
			system("cls");
			break;
		case 9:
			int usuarios;
			cout << "Ingrese el numero de usuarios a generar " << "\n";
			cin >> usuarios;
			cout << "\n\t Espere...  :D" << endl;
			controller->generador(usuarios);
			
			controller->generadorMostrar();
			cout << "\n\t Los datos de usuarios simulados han sido realizados de forma exitosa..." << endl;
			_getch();
			break;
		case 10:
			controller->imprimir_ordenar_table();
			_getch();
			break;
		case 11:
			do
			{
				system("cls");
				Console::ForegroundColor = ConsoleColor::Yellow;
				cout << "\t|------------------------------------|" << endl;
				cout << "\t| [1] Insertar pregunta al quizz     |" << endl;
				cout << "\t| [2] Comenzar Quizz                 |" << endl;
				cout << "\t| [3] Salir                          |" << endl;
				cout << "\t|------------------------------------|" << endl;
				cout << "\n\t    Ingresar opción:"; cin >> opc3;
				if (opc3 == 1) {
					string dp, dr;
					system("cls");
					cout << "\t APRENDE CON DIVERSIÓN! :D : " << endl; getline(cin, a);
					cout << "\t Ingrese pregunta: "; getline(cin, dp); cout << endl;
					cout << "\t Ingrese respuesta:"; getline(cin, dr); cout << endl;
					controller->add_quizz(dp, dr);
					cout << "\t "; system("pause");
				}
				if (opc3 == 2) {
					system("cls");
					controller->mostrar_quizz();
				}
			} while (opc3 != 3);


			break;
		case 12:
			exit(0);
			break;
		}
		auto fun = [opc2, controller]() {
			switch (opc2)
			{
			case 1:	
				controller->mostrarTareas(); 
				_getch(); break;
			case 2:controller->mostrarEventos(); _getch(); break;
			case 3:controller->mostrarRecordatorios(); _getch(); break;
			case 4:controller->mostrarNotas(); _getch(); break;
			case 5:
				int opc4, opc5; long aux;
				controller->mostrarAgenda();
				Console::ForegroundColor = ConsoleColor::Yellow;
				cout << "\t ¿Desea ordenar los teléfonos recientemente ingresados? (SI:1 / NO:2) ";
				cin >> opc4; cout << endl;
				if (opc4 == 1) {
					controller->ordenar();
					Console::ForegroundColor = ConsoleColor::Yellow;
					cout << "\t ¿Más información del teléfono? (Si:1 / NO:2) "; cin >> opc5; cout << endl;
					if (opc5 == 1) {
						cout << "\t Ingrese número de la reciente lista: "; cin >> aux;
						controller->Informacion(aux);
					}
				}
				_getch(); break;
			case 6:Console::ForegroundColor = ConsoleColor::Red;controller->mostrar_Musica();_getch();break;
			case 7:Console::ForegroundColor = ConsoleColor::Green;controller->mostrar_Horario();_getch();break;
			case 8:break;
			}
		};
		if (opc == 8){	fun();}
	}
	_getch();
	return 0;
}
