#include <iostream>
#include <string>
using namespace std;

struct pirkejas
{
	int nr;
	string var;
	struct pirkejas *kitas;
};
struct duomenys
{
	int bat[100];
	int batk=0;
	int l = 0;
	int v = 0;
};
int main()
{
	pirkejas* vid;
	duomenys duom;
	vid = NULL;
	int pas, i = 1;
	while (i==1)
	{
		cout << "---------------------------------" << endl;
		cout << "Meniu:" << endl;
		cout << "[1] Turimu batu dydziu ivedimas" << endl;
		cout << "[2] Pirkejo pastatymas i eile" << endl;
		cout << "[3] Aptarnauti pirkeja" << endl;
		cout << "[4] Informacija apie eiles" << endl;
		cout << "[5] Lauko eiles atlaisvinimas" << endl;
		cout << "[0] Sustabdyti programa" << endl;
		cout << "---------------------------------" << endl;
		cin >> pas;
		switch (pas)
		{
		case 0:
		{
			i = 0;
			break;
		}
		case 1:
		{
			system("cls");
			int kiek;
			cout << "Kiek skirtingu batu numeriu bus ivesta?" << endl;
			cin >> kiek;
			for (int i = duom.batk; i < duom.batk + kiek; i++)
			{
				cout << "Iveskite bato numeri: " << endl;
				cin >> duom.bat[i];
			}
			duom.batk += kiek;
			break;
		}
		case 2:
		{
			system("cls");
			pirkejas* V;
			V = vid;
			int kiek, pat;
			cout << "Kiek pirkeju bus statoma i eile?" << endl;
			cin >> kiek;
			for (int i = 0; i < kiek; i++)
			{
				cout << "Turimi batu numeriai" << endl;
				for(int j=0; j<duom.batk; j++)
				{
					cout << duom.bat[j] << " ";
				}
				cout << endl;
				cout << "Koks pirkejo bato numeris?" << endl;
				cin >> pat;
				for (int j = 0; j < duom.batk; j++)
				{
					if (duom.bat[j] == pat)
					{
						if (duom.v < 7 || (duom.v < 10 && duom.l == 0))
						{
							if (vid == NULL)
							{
								vid = new pirkejas;
								vid->nr = pat;
								cout << "Koks pirkejo vardas?" << endl;
								cin >> vid->var;
								vid->kitas = NULL;
							}
							else
							{
								V = vid;
								while (V->kitas != NULL) V = V->kitas;
								V->kitas = new pirkejas;
								V->kitas->nr = pat;
								cout << "Koks pirkejo vardas?" << endl;
								cin >> V->kitas->var;
								V->kitas->kitas = NULL;
							}
							duom.v++;
						}
						else
						{
							
							V = vid;
							while (V->kitas != NULL) V = V->kitas;
							V->kitas = new pirkejas;
							V->kitas->nr = pat;
							cout << "Koks pirkejo vardas?" << endl;
							cin >> V->kitas->var;
							V->kitas->kitas = NULL;
							duom.l++;
						}
					}
					else
					{
						kiek--;
						break;
					}
				}
				system("cls");
			}
			break;
		}
		case 3:
		{
			pirkejas* V;
			system("cls");
			V = vid;
			int j;
			if (duom.v==0 && duom.l==0)
			{
				cout << "Nera pirkeju kuriuos butu galima aptarnauti" << endl;
				break;
			}
			V = vid;
			cout << "Aptarnautas klientas: " << V->var << " numeris: " << V->nr << endl;
			vid = vid->kitas;
			delete V;
			duom.v--;
			if (duom.v <=7 && duom.l >= 3)
			{
				V=vid;
				j = 0;
				while (j != 7)
				{
					j++;
					V = V->kitas;
				}
				for(int i=0; i<3; i++)
				{
					cout << "I vidu ileistas klientas vardu: " << V->var << " jo numeris: " << V->nr << endl;
					V = V->kitas;
					duom.v++;
					duom.l--;
				}
				break;
			}
			if (duom.v<=7 && duom.l == 2)
			{
				V = vid;
				j = 0;
				while (j != 7)
				{
					j++;
					V = V->kitas;
				}
				for (int i = 0; i < 2; i++)
				{
					cout << "I vidu ileistas klientas vardu: " << V->var << " jo numeris: " << V->nr << endl;
					V = V->kitas;
					duom.v++;
					duom.l--;
				}
				break;
			}
			if(duom.v<=7 && duom.l ==1)
			{
				j = 0;
				while (j != 7)
				{
					j++;
					V = V->kitas;
				}
				for (int i = 0; i < 1; i++)
				{
					cout << "I vidu ileistas klientas vardu: " << V->var << " jo numeris: " << V->nr << endl;
					V = V->kitas;
					duom.v++;
					duom.l--;
				}
				break;
			}
			break;
		}
		case 4:
		{
			system("cls");
			cout << "Viduje laukia: " << duom.v << " klientai, lauke laukia: " << duom.l << " klientai" << endl;
			break;
		}
		case 5:
		{
			system("cls");
			int j = 0;
			pirkejas* V, *L;
			L = vid;
			while(j!=duom.v)
			{
				j++;
				vid = vid->kitas;
			}
			while (vid != NULL)
			{
				V = vid;
				vid = vid->kitas;
				delete V;
				duom.l--;
			}
			vid = L;
			cout << "Atlaisvinta lauko eilė" << endl;
			break;
		}
		default:
		{
			cout << "Ivesta neteisinga komanda, bandykite dar karta " << endl;
			break;
		}

		}
	}
}
