#include <iostream>
#include <string>
#include "../const/Constant.h"
#include "../tl/Controller.h"

using namespace std;

Controller* controller = new Controller();

string getArea() {
    string opc = "";
    do {
        cout << "Digite el area que desea" << endl;
        cout << "A- Area preferencial." << endl;
        cout << "B- Graderia preferencial." << endl;
        cout << "C- Graderia general." << endl;
        cin >> opc;
    } while (opc != "A" && opc != "B" && opc != "C");
    return opc;
}

int getAreaAPosition() {
    int opc = 0;
    do {
        cout << "Digite la posicion que desea" << endl;
        cout << "Inicia en asiento " + to_string(Constant::BeginPreferentialArea) << endl;
        cout << "Finaliza en asiento " + to_string(Constant::FinalPreferentialArea) << endl;
        cin >> opc;
    } while (opc < Constant::BeginPreferentialArea || opc > Constant::FinalPreferentialArea);
    return opc;
}

int getAreaCPosition() {
    int opc = 0;
    do {
        cout << "Digite la posicion que desea" << endl;
        cout << "Inicia en asiento " + to_string(Constant::BeginGeneralGrandstand) << endl;
        cout << "Finaliza en asiento " + to_string(Constant::FinalGeneralGrandstand) << endl;
        cin >> opc;
    } while (opc < Constant::BeginGeneralGrandstand || opc > Constant::FinalGeneralGrandstand);
    return opc;
}

int getSeatPosition() {
    string area = getArea();
    if (area == "A") {
        return getAreaAPosition();
    }
    if (area == "B") {
        return Constant::BeginPreferentialGrandstand1;
    }

    return getAreaCPosition();
}

void reserveSeat() {
    string name = "";
    int id = 0;
    cout << "Digite la cedula del cliente" << endl;
    cin >> id;
    cout << "Digite el nombre del cliente" << endl;
    cin >> name;
    int seatPosition = getSeatPosition();
    cout << controller->reserveSeat(id, name, seatPosition) << endl;
}

int main() {
    int opc = 0;
    string  area = "";
    do {
        cout << "Digite lo que desea hacer" << endl;
        cout << "1- Reservar espacio" << endl;
        cout << "2- Mostar cantidad de reservas por area" << endl;
        cout << "3- Mostar lista de espera por area" << endl;
        cout << "4- Salir" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                reserveSeat();
                break;
            case 2:
                area = getArea();
                cout << controller->showTotalReservesByArea(area) << endl;
                break;
            case 3:
                area = getArea();
                cout << controller->showWaitingListByArea(area) << endl;
                break;
            case 4:
                cout << "Cerrando sistema" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    } while (opc != 4);
    return 0;
}
