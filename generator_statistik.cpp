#include<iostream>
#include<math.h>
#include<iomanip>
#define MAX 0
using namespace std;
struct data{
	float strugt,pnjg_klst,bulat,bulats;
	int x,range,strug,pnjg_kls,max,min;
	int data[MAX];
};
data statistik;

struct data_bergolong{
	int interval;
	int intervals;
};
data_bergolong science;

void inputdata(){
	cout<<"Masukkan MAX array : ";
	cin>>statistik.x;
	
	for(int i=0; i<statistik.x; i++){
		cout<<"Masukkan Data ke  ["<<i<<"] = ";
		cin>>statistik.data[i];
	}
	system("cls");
}

void print_data(){
	cout<<"Data Yang anda Inputkan : { ";
	for(int i=0; i<statistik.x; i++){
		cout<<statistik.data[i];
		if(i==statistik.x-1)
		continue;
		else
		cout<<",";
	}cout<<" } ";
	cout<<endl;
	cout<<"Jumlah Data(n) = "<<statistik.x<<endl;
}
void shortingdata(){
	int temp;
	for(int i=0; i<statistik.x; i++){
		for(int j=i; j<statistik.x; j++){
			if(statistik.data[i]>statistik.data[j]){
				temp = statistik.data[i];
				statistik.data[i] = statistik.data[j];
				statistik.data[j] = temp;
			}
		}
	}
	cout<<"Data setelah di inurutkan : {";
	for(int i=0; i<statistik.x; i++){
		cout<<statistik.data[i];
		if(i==statistik.x-1)
		continue;
		else
		cout<<",";
	}cout<<"}";
	
}

void nilai_selection(){
	statistik.max = statistik.data[0];
	statistik.min = statistik.data[0];
	for(int i=0; i<statistik.x; i++){
		if(statistik.data[i]>statistik.max)
		statistik.max=statistik.data[i];
		if(statistik.data[i]<statistik.min)
		statistik.min=statistik.data[i];
	
	}
	statistik.range = statistik.max - statistik.min;
	cout<<"Range : "<<statistik.max<<" - "<<statistik.min<<" = "<<statistik.range;
}

void strugres(){
	statistik.strug = 1 + (3.3 * log10(statistik.x));
	statistik.strugt = 1 + (3.3 * log10(statistik.x));
	statistik.bulats = statistik.strugt-statistik.strug;
	if(statistik.bulats==0){
		cout<<"Jumlah Kelas(K) : "<<"1 + 3.3 * log("<<statistik.x<<") = "<<statistik.strug;
	}else{
		cout<<"Jumlah Kelas(K)-> dibulatkan ke atas  : "<<"1 + 3.3 * log("<<statistik.x<<") = "<<statistik.strug+1;
	}
}


void panjang_kls(){
	statistik.pnjg_kls = statistik.range/statistik.strugt;
	statistik.pnjg_klst = statistik.range/statistik.strugt;
	statistik.bulat = statistik.pnjg_klst-statistik.pnjg_kls;
	if(statistik.bulat>=0 && statistik.bulat<=0.5){
		cout<<"Panjang Kelas(P) : "<<statistik.range<<" : "<<statistik.strugt<<" = "<<statistik.pnjg_kls;
	}else{
		cout<<"Panjang Kelas(P) : "<<statistik.range<<" : "<<statistik.strugt<<" = "<<statistik.pnjg_kls + 1;
	}
}

void tabel_interval(){
	cout<<" +===========+"<<endl;
	cout<<" |  Interval | "<<endl;
	cout<<" +===========+"<<endl;
	if(statistik.bulats>=0 && statistik.bulats<=0.5){
		for(int i=0; i<statistik.strug+1; i++){
			science.intervals=(statistik.min + statistik.pnjg_kls)-1;
			cout<<"  |"<<setw(4)<<statistik.min<<" - "<<science.intervals<<" |";
			statistik.min = science.intervals+1;
			cout<<endl;
		}
	}else if(statistik.bulats>0.5 && statistik.bulats < 1 && statistik.bulat>=0 && statistik.bulat<=0.5){
		for(int i=0; i<statistik.strug+1; i++){
			science.interval=(statistik.min + statistik.pnjg_kls)-1;
			cout<<" |"<<setw(4)<<statistik.min<<" - "<<science.interval<<"  |";
			statistik.min = science.interval+1;
			cout<<endl;
		}
	}else if(statistik.bulats==0){
			for(int i=0; i<statistik.strug; i++){
			science.intervals=(statistik.min + statistik.pnjg_kls)-1;
			cout<<" |"<<setw(4)<<statistik.min<<" - "<<science.intervals<<" |";
			statistik.min = science.intervals+1;
			cout<<endl;
		}
	}else{
		for(int i=0; i<statistik.strug+1; i++){
			science.interval=(statistik.min + statistik.pnjg_kls+1)-2;
			cout<<" |"<<setw(4)<<statistik.min<<" - "<<science.interval+1<<"  |";
			statistik.min = science.interval+2;
			cout<<endl;
		}
	}
cout<<" +===========+"<<endl;


}

void cari_frek(){
	int total=0;
	cout<<"Data Frekuensi : "<<endl;
	for(int i=0; i<statistik.x; i++){
		int frek = 0;
		for(int j=0; j<statistik.x; j++){
			if(statistik.data[i]==statistik.data[j]){
			frek++;
		}
	}
	if(statistik.data[i] != statistik.data[i-1]){
	cout<<"Data : "<<statistik.data[i]<<" ada sebanyak = "<<frek<<endl;
	total = total+frek;}
	}
	cout<<endl<<endl;
	cout<<"Total Frekuensi adalah : "<<total<<endl;
}

void frekuensiku(){
	if(science.intervals > statistik.max)
	cout<<"Tabel diatas Valid"<<endl;
	else if(science.interval > statistik.max)
	cout<<"Tabel diatas Valid"<<endl;
	else
	cout<<"Tabel diatas tidak valid"<<endl;
}
clear_all(){
	for(int i=0; i<statistik.x; i++){
		statistik.data[i]=0;
	}
}

int main(){
int pilihan;
inputdata();
	do{
		print_data();
		cout<<endl;
		cout<<"+===========================+"<<endl;
		cout<<"| Manipulasi penyajian Data |"<<endl;
		cout<<"+===========================+"<<endl;
		cout<<"|1. Ubah ke Data Kelompok   |"<<endl;
		cout<<"|2. Cek Total Frekuensi     |"<<endl;
		cout<<"|3. Bersihkan Data          |"<<endl;
		cout<<"|4. Keluar                  |"<<endl;
		cout<<"+===========================+"<<endl;
		cout<<"Masukkan Pilihan : ";
		cin>>pilihan;
		cout<<endl;
		switch(pilihan){
			case 1 : 
			cout<<"+================================================+"<<endl;
			shortingdata();
			cout<<endl;
			nilai_selection();
			cout<<endl;
			strugres();
			cout<<endl;
			panjang_kls();
			cout<<endl<<endl;
			tabel_interval();
			cout<<endl;
			frekuensiku();
			cout<<"+===============================================+"<<endl<<endl;
			system("pause");
			system("cls");
			break;
		
			case 2 :
			cout<<"+================================================+"<<endl;
			shortingdata();
			cout<<endl;
			nilai_selection();
			cout<<endl;
			strugres();
			cout<<endl;
			panjang_kls();
			cout<<endl<<endl;
			tabel_interval();
			cout<<endl<<endl;
			cari_frek();
			cout<<endl<<endl;
			frekuensiku();
			cout<<"+===============================================+"<<endl<<endl;
			system("pause");
			system("cls");
			break;
			
			case 3 :
			clear_all();
			system("cls");
			inputdata();
			break;
			
			case 4 :
			exit(0);
			default :
				cout<<"Pilihan Tidak Tersedia"<<endl;
				break;
		}}while(pilihan!=6);
}
