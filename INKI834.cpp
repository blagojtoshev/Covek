#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
//definiranje na struktura
struct Covek
{
	int RedenBroj;
	string ime;
	float poeni;

}covek;
//definiranje na metoda za sortiranje
bool Sortiranje(const Covek &c1,const Covek &c2){
 		return c1.poeni>c2.poeni;
	 }
//funkcija za vnesuvanje na niza od luge
void vnesiCovek(struct Covek covek[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n Vnesete reden broj : ";
		cin>>covek[i].RedenBroj;
		cout<<"\n Vnesete ime : ";
		cin>>covek[i].ime;
		cout<<"\n Vnesete poeni : ";
		cin>>covek[i].poeni;
	}
}
int main()
{
	//deklaracija na instanca
	struct Covek covek[100];
	vector<struct Covek> vekCovek(100);

	int n;
	cout<<"\n Vnesete broj na elementi : ";
	cin>>n;
	vnesiCovek(covek,n);
	//dodeluvanje na niza od struktura vo vektor
	for(int i=0;i<n;i++)
	vekCovek.push_back(covek[i]);
	//prikaz na podatoci
	cout<<"\n Pecatenje na podatocite koi se vneseni  : "<<endl;
	for(vector<Covek>::iterator itr=vekCovek.begin();itr<vekCovek.end();++itr)
	{
		if(itr->RedenBroj!=0)
		{
			//pecatenje na podatoci preku iterator
			cout<<endl;
			cout<<"\t"<<itr->RedenBroj<<"  ";
			cout<<"\t"<<(*itr).ime<<"  ";
			cout<<"\t"<<(*itr).poeni<<"   ";
		}
	}
	//povik na metoda sortiranje
	sort(vekCovek.begin(),vekCovek.end(),Sortiranje);
	//prikaz na podatoci sortirani
	cout<<endl<<endl;
	cout<<"\n Pecatenje na podatocite sortirani po poeni : ";
	//pecatenje na podatoci koi se sortirani preku iterator
	for(vector<Covek>::iterator itr=vekCovek.begin();itr<vekCovek.end();++itr)
	{
		if(itr->RedenBroj!=0)
		{
			cout<<endl;
			cout<<"\t"<<itr->RedenBroj<<"  ";
			cout<<"\t"<<(*itr).ime<<"  ";
			cout<<"\t"<<(*itr).poeni<<"   ";
		}
	}
	//zapisuvanje na podatocite vo datoteka
	ofstream datotekaVektor("Covek.txt");
	cout<<endl<<endl;
	datotekaVektor<<"Spisok na luge koi se sortirani po broj poeni "<<endl;
	for(vector<Covek>::iterator itr=vekCovek.begin();itr<vekCovek.end();++itr)
	{
		if(itr->RedenBroj!=0)
		{
			//zapisuvanje na podtaocite vo datoteka preku iterator
			datotekaVektor<<endl;
			datotekaVektor<<"\t"<<itr->RedenBroj<<"  ";
			datotekaVektor<<"\t"<<(*itr).ime<<"  ";
			datotekaVektor<<"\t"<<(*itr).poeni<<"   ";
		}
	}
	datotekaVektor.close();
}
