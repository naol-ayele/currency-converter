
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#define ETH_CUR 1 //type of macros (object like macros)
#define ERT_CUR 2
#define RWD_CUR 3
#define DJF_CUR 4
#define BIF_CUR 5
#define KSH_CUR 6
#define TZS_CUR 7
#define SOS_CUR 8
#define UGX_CUR 9

#define T_ETB 	"ETB"
#define T_ERT 	"ERN"
#define T_RWD 	"RWD"
#define T_DJF 	"DJF"
#define T_BIF 	"BIF"
#define T_KSH 	"KSH"
#define T_TZS 	"TZS"
#define T_SOS 	"SOS"
#define T_UGX 	"UGX"

typedef struct CountryCurrency{
	string country;
	double inDollar;
	double inPound;
	double inEuro;
}CountryCurrency;
// declaration part
short countryChooser();// to choose which country currency we need to convert
CountryCurrency getCurrencyProp(int);// to get relation between East African country currency and global currency
short currencyChooser(string);
void converter();

double euroToX(CountryCurrency, double);
double dollarToX(CountryCurrency, double);
double poundToX(CountryCurrency, double);

double xToEuro(CountryCurrency, double);
double xToDollar(CountryCurrency, double);
double xToPound(CountryCurrency, double);

int main(){
	converter();
	cout<<endl<<setw(17)<<"GROUP MEMBER"<<setw(20)<<"ID NO"<<setw(14)<<"SEC"<<endl
	<<setw(17)<<"1. NAOL AYELE"<<setw(22)<<"UGR/25391/14"<<setw(12)<<"37"<<endl
	<<setw(20)<<"2. SAMUEL ASSEFA"<<setw(19)<<"UGR/25529/14"<<setw(12)<<"37"<<endl
	<<setw(22)<<"3. BINYAM BIYADGIE"<<setw(17)<<"UGR/26612/14"<<setw(12)<<"37"<<endl;
	
}

/// definitions
short countryChooser(){
	cout<<setw(35)<<"#WELCOME#"<<endl;
	cout<<"THIS IS CURRENCY CONVERTER USED FOR CONVERT"<<endl
	<<"EAST AFRICAN COUNTRY CURRENCY(EACC) TO GLOBAL CURRENCY "<<endl<<endl<<endl;
	cout<<"Select your EACC option <1-9>"<<endl;
	cout<<"1. Ethiopian Birr(ETB)"<<endl
	<<"2. Eritrean Nakfa(ERN)"<<endl
	<<"3. Rwandan Franc(RWF)"<<endl
	<<"4. Djiboutian Franc(DJF)"<<endl
	<<"5. Burundian Franc(BIF)"<<endl
	<<"6. Kenyan Shilling (KSh)"<<endl
	<<"7. Tanzanian Shilling (TZS)"<<endl
	<<"8. Somalian Shilling(SOS)"<<endl
	<<"9. Ugandan Shilling (UGX)"<<endl
	<<">>> ";

	short choice = 0;
	cin>>choice;
	return choice;
}


CountryCurrency getCurrencyProp(int country){
	CountryCurrency cc;
	switch(country){
		case ETH_CUR:
			cc.country = T_ETB;
			cc.inDollar = 0.0186;// one birr to dollar
			cc.inPound = 0.0153;// one birr to pound
			cc.inEuro = 0.0173;// one birr to euro
		break;

		case ERT_CUR:
			cc.country = T_ERT;
			cc.inDollar = 0.06667;// one nakfa to dollar
			cc.inPound = 0.054946;// one nakfa to pound
			cc.inEuro = 0.06;// one nakfa to euro
		break;

		case RWD_CUR:
			cc.country = T_RWD;
			cc.inDollar = 0.0009334;// one RWD to dollar
			cc.inPound = 0.0007683;// one RWD to pound
			cc.inEuro = 0.0008698;// one RWD to euro
		break;

		case DJF_CUR:
			cc.country = T_DJF;
			cc.inDollar = 0.005615;// one DJF to dollar
			cc.inPound = 0.004622;// one DJF to pound
			cc.inEuro = 0.005233;// one DJF to euro
		break;

		case BIF_CUR:
			cc.country = T_BIF;
			cc.inDollar = 0.0004822;// one BIF to dollar
			cc.inPound = 0.0003969;// one BIF to pound
			cc.inEuro = 0.0004493;// one BIF to euro
		break;

		case KSH_CUR:
			cc.country = T_KSH;
			cc.inDollar = 0.008081;// one KSH to dollar
			cc.inPound = 0.006652;// one KSH to pound
			cc.inEuro = 0.008698;// one KSH to euro
		break;

		case TZS_CUR:
			cc.country = T_TZS;
			cc.inDollar = 0.0004288;// one TZS to dollar
			cc.inPound = 0.000353;// one TZS to pound
			cc.inEuro = 0.0003996;// one TZS to euro
		break;

		case SOS_CUR:
			cc.country = T_SOS;
			cc.inDollar = 0.001758;// one SOS to dollar
			cc.inPound = 0.001447;// one SOS to pound
			cc.inEuro = 0.001639;// one SOS to euro
		break;

		case UGX_CUR:
			cc.country = T_UGX;
			cc.inDollar = 0.0002698;// one UGX to dollar
			cc.inPound = 0.0002221;// one UGX to pound
			cc.inEuro = 0.0002514;// one UGX to euro

	}
	return cc;
}

short currencyChooser(string code){
	cout<<"choose the converter"<<endl
	<<"1. "<<code<<" to DOLLAR"<<endl
	<<"2. "<<code<<" to POUND"<<endl
	<<"3. "<<code<<" to EURO"<<endl
	<<"4. DOLLAR to "<<code<<endl
	<<"5. POUND to "<<code<<endl
	<<"6. EURO to "<<code<<endl
	<<">>> ";
	short choice = 0;
	cin>>choice;
	return choice;
}


// calling part
void converter(){
	const short country = countryChooser();
	if(country < 1 || country > 9){
		cout<<"INVALID COUNTRY!"<<endl;
		exit(1);
	}

	CountryCurrency cc = getCurrencyProp(country);
	short chosen = currencyChooser(cc.country);
	cout<<"enter amount of money"<<endl
		<<">>> ";
	double amount;
	cin>>amount;
	switch (chosen) {
		case 1:
			cout<<amount<<" "<<cc.country<<" to dollar is: "<<xToDollar(cc, amount)<<endl;
			break;
		case 2:
			cout<<amount<<" "<<cc.country<<" to pound is: "<<xToPound(cc, amount)<<endl;
			break;
		case 3:
			cout<<cc.country<<" to euro is: "<<xToEuro(cc, amount)<<endl;
			break;
		case 4:
			cout<<"dollar to"<<cc.country<<" is: "<<dollarToX(cc, amount)<<endl;
			break;
		case 5:
			cout<<"pound to "<<cc.country<<" is: "<<poundToX(cc, amount)<<endl;
			break;
		case 6:
			cout<<"euro to "<<cc.country<<" is: "<<euroToX(cc, amount)<<endl;
			break;
	}

}
///definition for money converter
double dollarToX(CountryCurrency c, double amount){
	return (1.0 / c.inDollar) * amount;
}

double poundToX(CountryCurrency c, double amount){
	return (1.0 / c.inPound) * amount;
}

double euroToX(CountryCurrency c, double amount){
	return (1.0 / c.inPound) * amount;
}

double xToDollar(CountryCurrency c, double amount){
	return c.inDollar * amount;
}
double xToPound(CountryCurrency c, double amount){
	return c.inPound * amount;
}
double xToEuro(CountryCurrency c, double amount){
	return c.inEuro * amount;
}

