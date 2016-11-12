#include "mutacion.h"
#include "enfermedad.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

   mutacion m=mutacion("1	1014143	rs786201005	C	T,T,GG	.	.	RS=786201005;RSPOS=1014143;dbSNPBuildID=144;SSR=0;SAO=1;VP=0x050060000605000002110100;GENEINFO=ISG15:9636|ISG15:9636;WGT=1;VC=SNV;PM;NSN;REF;ASP;LSD;OM;CLNALLE=1;CLNHGVS=NC_000001.11:g.1014143C>T;CLNSRC=OMIM_Allelic_Variant;CLNORIGIN=1;CLNSRCID=147571.0003;CLNSIG=5;CLNDSDB=MedGen:OMIM;CLNDSDBID=CN221808:616126;CLNDBN=Immunodeficiency_38_with_basal_ganglia_calcification;CLNREVSTAT=no_criteria;CLNACC=RCV000162196.3;COMMON=1");

   cout << "CROMOSOMA: " << m.getChr() << "\n";
   cout << "POS: " << m.getPos() << "\n";
   cout << "ID: " << m.getID() << "\n";
   cout << "REF ALT: ";
   for (int i=0;i<m.getRef_alt().size();i++){
     if(i==m.getRef_alt().size()-1){
       cout << getVectorData(m.getRef_alt(),i) << "\n";
     }else{
       cout << getVectorData(m.getRef_alt(),i) << ",";}
    }
    cout << "GENES: ";
    for (int i=0;i<m.getGenes().size();i++){
      if(getVectorData(m.getGenes(),i)=="|"){
          cout << ",";
      }else{
        cout << getVectorData(m.getGenes(),i) << "\n";
      }
    }
    cout << "COMMON: " << m.getCommon() << "\n";
    //cout << "CAF: " << m.getCaf() << "\n";
   return 0;
}
