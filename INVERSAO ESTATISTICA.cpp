#include <iostream>
#include <fstream>
using namespace std;

//[fstream DECLARA]

int main () {
	
int hora, minut, minutd, dia,diad,mes,ano,time;
int abert, max,maxd, min,mind, fech,fechd,cprej=0,clucro=0,exc=0;
int entrada, alvo, stop, parcial=200000, cparcial, valor_parcial, stop_parcial;
int x=0,y,y1;
int lucro=0,prej=0,saldo,saldot;
int gain,gain2,loss,loss2,yes=0;
int modo, control, dados, ctt=0, ctt_parcial, abert_valid=0, stoplongo=0;

printf( "digite a hora:\n");
scanf("\n%d",&time);

printf( "selecione o banco de dados [1][2][3]:\n");
scanf("\n%d",&dados);

//printf( "Stop LONGO sim[1] nao[2]\n");
//scanf("\n%d",&stoplongo);
stoplongo=1;

//printf( "\n\nFormato resumido? 1==nao 2==sim  :\n");
//scanf("\n%d",&control);
control=1;

//printf( "MODO DE ANALISE SIMPLES [1] - COMPLETO* [2]\n");
//scanf("\n%d",&modo);
modo=2;

printf( "\n\n ALVO em pontos. ex: 250\n");
scanf("\n%d",&gain);
gain2=gain;

printf( " STOP em pontos. ex: 250\n");
scanf("\n%d",&loss);
loss2=loss;

// ************************ //////////////////////////////////////////////////////////////////////////////////////////////  // reinicia o programa

while (yes==0){  
lucro=0, prej=0, y1=0, x=0, y=1, clucro=0,cprej=0,cparcial=0 , stop_parcial=0;                                             // zeragem

ofstream out; 
out.open ("ESTATISTICAS com INVERSAO.txt",ios_base::app);

//,ios_base::app

ifstream in; 


if      (dados==1){
in.open("dados1.txt");

}
else if (dados==2){
in.open("dados2.txt");
	
	
}
else if (dados==3){
in.open("dados3.txt");
	
	
}
else if (dados==4){
in.open("dados4.txt");
	
	
}
else if (dados==5){
in.open("dados5.txt");
	
	
}

// ************************************************************************************************************************************************* MODO 1 *******//

if(modo==0){
	printf( "\n\n\n FIM     ---modo 0\n");
	system("pause");
}


if(modo==1){

modo=0;

valor_parcial = gain * 2; // desativa parcial


out << "\n==========================================================================================================================================1";
out << "\n==========================================================================================================================================";
out << "\n\nRELATORIO ESTATISCO VENDIDO\nALVO: " << gain <<"\nSTOP: " << loss << "\nHORA: " << time  << "h05.\n\n";



}


// ********************************************************************************************************************************************** MODO 2 **********//

if(modo==2){

loss=loss2;

loss=loss+10;

loss2=loss;

gain=gain2;

valor_parcial = gain * 2; // desativa parcial, tbm quebra o else if...

if (loss>=400){
system("pause");	
}

out << "\nINVERSAO VENDIDO==========================================================================================================================================";

out << "\n\nRELATORIO ESTATISCO --> VENDIDO\nALVO: " << gain <<"\nSTOP: " << loss << "\nHORA: " << time  << "h05.\n\n";


} // fim modo


if(stoplongo==1){
	
	out << "STOP LONGO\n";
	
	}else{																								// SELEÇÃO STOP NA INVERSAO
	
	out << "STOP CURTO\n";
	
	}
if(dados==1){
	
	out << "BANCO DE DADOS 1\n";
	
	}
	else if(dados==2){																					//SELEÇÃO BANCO DE DADOS
	
	out << "BANCO DE DADOS 2\n";
	
	

	}else if(dados==3){
	
	out << "BANCO DE DADOS 3\n";
	


	}else if(dados==4){
	
	out << "BANCO DE DADOS 4\n";
	
	
	
	}else if(dados==5){
	
	out << "BANCO DE DADOS 5\n";
	
	}

// ******************************************************************************************************************************************** INICIO ALGORITMO VENDIDO************//
while (x == 0 ) // inicia o programa
{
// coleta dados do txt sem : e / 

in >> dia >> mes >> ano >> hora >> minut >> abert >> max >> min >> fech;


if (dia == 111){
	//out << "\n==========================================================================================================================================";
	
	out << "\nPERIODO DE "<< mes << "/" << ano <<" ATE " << hora <<"/"<< minut;

	if(control==1){

	out << "\n\n\n\n==========================================================================================================================================";

	}
	}



if ( hora == 17 && minut == 45 && y==0){
	
	printf("\n%d/%d/%d     %d:%d -- %d",dia,mes,ano,hora,minut,entrada); 
	
	
	if(control==1){
	
	
	
	if(fech <= entrada ){
		
	out << "\nPARC "<< dia << "/" << mes << " ---P --- --- sem STOP/ALVO -------------------- exception positivo ";
	
	} else if (fech >= entrada){
		
	out << "\nPARC "<< dia << "/" << mes << " ---P --- --- sem STOP/ALVO -------------------- exception negativo ";	
		
	}
	
   }
	
	
	y1=1,y=1;
	//stop_parcial++;
	exc++;
	
}



if (hora==time && minut==5){

	entrada=abert;
	alvo=entrada-gain;
	stop=entrada+loss;
	diad=dia;
	y=0;
	y1=0;
	//abert_valid=1;
	parcial = entrada - valor_parcial;
	

}


if  ( parcial > min && y1==0 && max < stop && y==0){
	
	//out << "\n--- --- --- PARCIAL " << dia << "/" << mes ;
	//y1=1;
    //cparcial++;
   // out << "\n ---exception parcial sem vergonha " << y << "  dia  " << dia ;
    
}

if ( alvo > min && y==0 && max < stop){
	
	//printf("\n%d/%d/%d     %d:%d -- %d",dia,mes,ano,hora,minut,entrada); 
	//printf("-----------------------alvo ok");
	y=1;
	lucro = lucro + gain / 5;
	clucro++;
     printf("\n gainnnn %d",y);
     
    if(control==1){ 
	out << "\nALVO " << dia << "/" << mes << " ---P --- --- --- --- --- --- --- --- ALVO " ;
}
	
	//out << "\n --- alvo" << dia << "/" << mes ;
//	out << " \n--------------------------------------------------gain- " << dia << "/" << mes ;

}else if(max > stop && y==0){
	
	//printf("\n---%d/%d/%d     %d:%d -- %d",dia,mes,ano,hora,minut,entrada);
	//printf("-----------------------STP ok");
	y=1;
	prej = prej + loss / 5;
	cprej++;
	
	if(control==1){
	out << " \nSTOP " << dia << "/" << mes ;
	
	printf("\n losss %d",y);
}
	if(y1==1){	
	out << " ---P  ---  ---  --- PARCIAL COM STOP " ;
	stop_parcial++;}
}

if(minut==minutd && max==maxd && fech==fechd && min==mind){

out << "\n QUEBRA LOOP ===========================================  ========================= ";
 x=1;
 
 
 } //quebra loop
 
 
minutd=minut; 
maxd=max; // contadores loop
fechd=fech;
mind=min;

}
// ******************************************************************************************************************************************* FIM ALGORITMO VENDIDO *************//

gain = gain / 5;
loss = loss / 5;


saldo = lucro-prej;
saldot=saldo;

if(control==1){
out << "\n\n\n\n\nVENDIDO \n\n ";
out << "\n " << time << "h05 --->   GAIN: " << lucro <<",00 ("  << clucro << "x" << gain <<  ")     STOP: " << prej <<",00 ("  << cprej  <<"x" << loss << ")      ============ SALDO 1 CTT: "<< saldo << ",00\n ";
}

gain = gain * 5;
loss = loss * 5;
lucro = lucro * 5; // 5ctt
prej = prej * 5;
saldo = lucro-prej;

if(control==1){
out << "\n " << time << "h05 --->   GAIN: " << lucro <<",00 ("  << clucro << "x" << gain <<  ")     STOP: " << prej <<",00 ("  << cprej  <<"x" << loss << ")      ============ SALDO 5 CTT: "<< saldo << ",00\n ";
}

gain = gain * 2;
loss = loss * 2;
lucro = lucro * 2; // 10ctt
prej = prej * 2;
saldo = lucro-prej;

if(control==1){
out << "\n " << time << "h05 --->   GAIN: " << lucro <<",00 ("  << clucro << "x" << gain <<  ")     STOP: " << prej <<",00 ("  << cprej  <<"x" << loss << ")      ============ SALDO 10 CTT: "<< saldo << ",00\n ";
}

gain = gain * 2;
loss = loss * 2;
lucro = lucro * 2; // 20ctt
prej = prej * 2;
saldo = lucro-prej;

if(control==1){
out << "\n " << time << "h05 --->   GAIN: " << lucro <<",00 ("  << clucro << "x" << gain <<  ")     STOP: " << prej <<",00 ("  << cprej  <<"x" << loss << ")      ============ SALDO 20 CTT: "<< saldo << ",00\n ";
}

gain = gain * 5;
loss = loss * 5;
lucro = lucro * 5; // 100ctt
prej = prej * 5;
saldo = lucro-prej;

if(control==1){
out << "\n " << time << "h05 ->   GAIN: " << lucro <<",00 ("  << clucro << "x" << gain <<  ")     STOP: " << prej <<",00 ("  << cprej  <<"x" << loss << ")      === SALDO 100 CTT: "<< saldo << ",00\n\n\n\n\n ";
}





in.close();
out.close();
// ******************************************************************************************************************************************* inicio COMPRADO *************//



gain = (gain /100)*5;
loss = (loss /100)*5;
lucro=0, prej=0, y1=0, x=0, y=1, clucro=0,cprej=0,cparcial=0 , stop_parcial=0;                                             // zeragem

//ofstream out; 
out.open ("ESTATISTICAS com INVERSAO.txt",ios_base::app);

//,ios_base::app

//ifstream in; 

if      (dados==1){
in.open("dados1.txt");

}
else if (dados==2){
in.open("dados2.txt");
	
	
}
else if (dados==3){
in.open("dados3.txt");
	
	
}
else if (dados==4){
in.open("dados4.txt");
	
	
}
else if (dados==5){
in.open("dados5.txt");
	
	
}

if(control==1){

out << "\n\n\n\n==========================================================================================================================================2";

out << "\nRELATORIO ESTATISCO --> COMPRADO\nALVO: " << gain <<"\nSTOP: " << loss << "\nHORA: " << time  << "h05.\n";
if(stoplongo==1){
	
	out << "STOP LONGO\n\n";
	
	}else{
	
	out << "STOP CURTO\n\n";
	
	}
}

// ******************************************************************************************************************************************** INICIO ALGORITMO COMPRADO ************//
while (x == 0 ) // inicia o programa comprado
{
// coleta dados do txt sem : e / 

in >> dia >> mes >> ano >> hora >> minut >> abert >> max >> min >> fech;

if ( hora == 17 && minut == 45 && y==0  ){
	
	printf("\n%d/%d/%d     %d:%d -- %d",dia,mes,ano,hora,minut,entrada); 
	
	if(control==1){
		
		
	if(fech >= entrada && abert_valid == 1){
		
	out << "\nPARC "<< dia << "/" << mes << " ---P --- --- sem STOP/ALVO -------------------- exception positivo ";
	
	} else if (abert_valid == 1){
		
	out << "\nPARC "<< dia << "/" << mes << " ---P --- --- sem STOP/ALVO -------------------- exception negativo ";	
		
	}
	
	
	}
	
	y1=1,y=1;
	//stop_parcial++;
	exc++;
	
}

if (hora==time && minut==5){

	entrada=abert+loss;
	alvo=entrada+(gain-loss);
	
	if(stoplongo==1){
	
	stop=abert-loss; // stop 2x o inicial
	
	}else{
	
	stop=abert;
	
	}
		
	diad=dia;
	y=0;
	y1=0;
	abert_valid=0;
	
	printf("\n  ENTRADA %d - ALVO /%d - STOP /%d - ABERTURA %d",entrada,alvo,stop,abert);
	
	parcial = entrada - valor_parcial;
}

if (max >= entrada){
	
	abert_valid=1;
}

if  ( parcial > min && y1==0 && max < stop && y==0){
	
	//out << "\n--- --- --- PARCIAL " << dia << "/" << mes ;
	//y1=1;
    //cparcial++; 
         
}else if ( alvo < max && y==0 && min > stop){
	
	//printf("\n%d/%d/%d     %d:%d -- %d",dia,mes,ano,hora,minut,entrada); 
	//printf("-----------------------alvo ok");
	y=1;
	lucro = lucro + (gain-loss) / 5;
	clucro++;

if(control==1){
	out << "\nALVO " << dia << "/" << mes << " ---P --- --- --- --- --- --- --- --- ALVO " ;
}
	
        
}else if(min <= stop && y==0 && abert_valid == 1){
	
	//printf("\n---%d/%d/%d     %d:%d -- %d",dia,mes,ano,hora,minut,entrada);
	//printf("-----------------------STP ok");
	y=1;
	prej = prej + loss / 5;
	cprej++;
	
	if(control==1){
	out << " \nSTOP " << dia << "/" << mes ;
}
	
	
	if(y1==1){	
	out << " ---P  ---  ---  --- PARCIAL COM STOP " ;
	stop_parcial++;}
}

if(minut==minutd && max==maxd && fech==fechd && min==mind){ 
out << "\n QUEBRA LOOP ===========================================  ========================= ";
x=1;

} //quebra loop

minutd=minut;
maxd=max; // contadores loop
fechd=fech;
mind=min;

}


if (stoplongo==1){
prej = prej*2; // trata o stop maior, seria o stop equivalente a entrada na abertura, ou seja, 2 x stop atual.
}

gain = gain / 5;

loss = loss / 5;

gain = gain - loss;  // trata a inversão

if (stoplongo==1){
loss = loss * 2; // trata stop maior no txt
}

saldo = lucro-prej;

saldot = saldot + saldo;

if(control==1){
out << "\n\n\n\n\nCOMPRADO \n\n ";
out << "\n " << time << "h05 --->    GAIN: " << lucro <<",00 ("  << clucro << "x" << gain <<  ")     STOP: " << prej <<",00 ("  << cprej  <<"x" << loss << ")      ============ SALDO 1 CTT: "<< saldo << ",00\n ";
}

gain = gain * 5;
loss = loss * 5;
lucro = lucro * 5; // 5ctt
prej = prej * 5;
saldo = lucro-prej;

if(control==1){
out << "\n " << time << "h05 --->   GAIN: " << lucro <<",00 ("  << clucro << "x" << gain <<  ")     STOP: " << prej <<",00 ("  << cprej  <<"x" << loss << ")      ============ SALDO 5 CTT: "<< saldo << ",00\n ";
}

gain = gain * 2;
loss = loss * 2;
lucro = lucro * 2; // 10ctt
prej = prej * 2;
saldo = lucro-prej;

if(control==1){
out << "\n " << time << "h05 --->  GAIN: " << lucro <<",00 ("  << clucro << "x" << gain <<  ")     STOP: " << prej <<",00 ("  << cprej  <<"x" << loss << ")      ============ SALDO 10 CTT: "<< saldo << ",00\n ";
}

gain = gain * 2;
loss = loss * 2;
lucro = lucro * 2; // 20ctt
prej = prej * 2;
saldo = lucro-prej;

if(control==1){
out << "\n " << time << "h05 --->  GAIN: " << lucro <<",00 ("  << clucro << "x" << gain <<  ")     STOP: " << prej <<",00 ("  << cprej  <<"x" << loss << ")      ============ SALDO 20 CTT: "<< saldo << ",00\n ";
}

gain = gain * 5;
loss = loss * 5;
lucro = lucro * 5; // 100ctt
prej = prej * 5;
saldo = lucro-prej;

if(control==1){
out << "\n " << time << "h05 ->  GAIN: " << lucro <<",00 ("  << clucro << "x" << gain <<  ")     STOP: " << prej <<",00 ("  << cprej  <<"x" << loss << ")      === SALDO 100 CTT: "<< saldo << ",00\n";
}


if(control==1){
out << "\n\n\n\n==========================================================================================================================================";
}

out << "\n\nRESULTADO TOTAL COMPRADO/VENDIDO ";


out << "\n\nSALDO GERAL 1ctt: " << saldot<<",00";
saldot = saldot * 5;
out << "\nSALDO GERAL 5ctt: " << saldot<<",00";
saldot = saldot * 2;
out << "\nSALDO GERAL 10ctt: " << saldot<<",00";
saldot = saldot * 2;
out << "\nSALDO GERAL 20ctt: " << saldot<<",00";
saldot = saldot * 5;
out << "\nSALDO GERAL 100ctt: " << saldot<<",00";

out << "\n\n\n\n==========================================================================================================================================";
//out << "\n========================================================================================================================================== FIM";
out << "\n------------------------------------------------------------------------------------------------------------------------------------------ ";
in.close();
out.close();






//system("pause");
}


printf("\n\n\n");
system("pause");
return 0;
}


