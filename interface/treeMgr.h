#ifndef __TREEMGR_H__
#define __TREEMGR_H__
#include <memory.h>
#include "TTree.h"
#include "TDirectory.h"

#include "/home/ltsai/Work/github/xPhoton/interface/readMgr.h"

// you can only load ONE readBrahBrah.h in the analysis.
#include "/home/ltsai/Work/github/xPhoton/interface/readgganalysis.h"
#include "/home/ltsai/Work/github/xPhoton/interface/logger.h"

struct treeMgr
{


    TTree* RegOutputTree(const std::string& name, TDirectory* _dir = nullptr)
    {
        LOG_INFO( "In directory %s constructs tree in name : %s", _dir ? _dir->GetName() : "current directory", name.c_str() );
        if ( _dir ) _dir->cd();
        t = new TTree( name.c_str(), name.c_str() );

        LOG_INFO("Building format of output tree");
        t->Branch("run",&run,"run/I");
        t->Branch("event",&event,"event/L");
        t->Branch("isData",&isData,"isData/O");
        t->Branch("HLT",&HLT,"HLT/L");
        t->Branch("HLTIsPrescaled",&HLTIsPrescaled,"HLTIsPrescaled/L");
        t->Branch("HLT50ns",&HLT50ns,"HLT50ns/L");
        t->Branch("HLTIsPrescaled50ns",&HLTIsPrescaled50ns,"HLTIsPrescaled50ns/L");
        t->Branch("phoFiredTrg",&phoFiredTrgs,"phoFiredTrgs/I");

        t->Branch("pthat",&pthat,"pthat/F");
        t->Branch("genHT",&genHT,"genHT/F");
        t->Branch("mcPt",&mcPt,"mcPt/F");
        t->Branch("mcEta",&mcEta,"mcEta/F");
        t->Branch("mcPhi",&mcPhi,"mcPhi/F");
        t->Branch("mcCalIso04",&mcCalIso04,"mcCalIso04/F");
        t->Branch("mcTrkIso04",&mcTrkIso04,"mcTrkIso04/F");
        t->Branch("recoPt",&recoPt,"recoPt/F");
        t->Branch("recoEta",&recoEta,"recoEta/F");
        t->Branch("recoPhi",&recoPhi,"recoPhi/F");
        t->Branch("recoSCEta",&recoSCEta,"recoSCEta/F");
        t->Branch("r9",&r9,"r9/F");
        t->Branch("isMatched",&isMatched,"isMatched/I");
        t->Branch("isMatchedEle",&isMatchedEle,"isMatchedEle/I");
        t->Branch("isConverted",&isConverted,"isConverted/I");
        t->Branch("idLoose",&idLoose,"idLoose/I");
        t->Branch("idMedium",&idMedium,"idMedium/I");
        t->Branch("idTight",&idTight,"idTight/I");
        t->Branch("nVtx",&nVtx,"nVtx/I");
        t->Branch("nPU",&nPU,"nPU/I");
        t->Branch("puwei",&puwei,"puwei/F");
        t->Branch("eleVeto",&eleVeto,"eleVeto/I");
        t->Branch("HoverE",&HoverE,"HoverE/F");
        t->Branch("sieie",&sieie,"sieie/F");
        t->Branch("sieip",&sieip,"sieip/F");
        t->Branch("sipip",&sipip,"sipip/F");
        t->Branch("chIso",&chIso,"chIso/F");
        t->Branch("phoIso",&phoIso,"phoIso/F");
        t->Branch("nhIso",&nhIso,"nhIso/F");
        t->Branch("chIsoRaw",&chIsoRaw,"chIsoRaw/F");
        t->Branch("chWorstRaw",&chWorstIso,"chWorstIso/F");
        t->Branch("phoIsoRaw",&phoIsoRaw,"phoIsoRaw/F");
        t->Branch("nhIsoRaw",&nhIsoRaw,"nhIsoRaw/F");
        t->Branch("rho",&rho,"rho/F");
        t->Branch("e1x3",&e1x3,"e1x3/F");
        t->Branch("e2x2",&e2x2,"e2x2/F");
        t->Branch("e2x5",&e2x5,"e2x5/F");
        t->Branch("e5x5",&e5x5,"e5x5/F");
        t->Branch("rawE",&rawE,"rawE/F");
        t->Branch("scEtaWidth",&scEtaWidth,"scEtaWidth/F");
        t->Branch("scPhiWidth",&scPhiWidth,"scPhiWidth/F");
        t->Branch("esRR",&esRR,"esRR/F");
        t->Branch("esEn",&esEn,"esEn/F");
        t->Branch("mva",&mva,"mva/F");
        t->Branch("photonIDmva",&photonIDmva,"photonIDmva/F");
        t->Branch("phoIDbit",&phoIDbit,"phoIDbit/I");
        t->Branch("mva_hgg",&mva_hgg,"mva_hgg/F");
        t->Branch("HggPresel",&HggPresel,"HggPresel/I");
        t->Branch("Mmm",&Mmm,"Mmm/F");
        t->Branch("Mee",&Mee,"Mee/F");
        t->Branch("MET",&MET,"MET/F");
        t->Branch("metFilters",&metFilters,"metFilters/I");
        t->Branch("METPhi",&METPhi,"METPhi/F");
        t->Branch("phohasPixelSeed",&phohasPixelSeed,"phohasPixelSeed/I");
        t->Branch("MTm",&MTm,"MTm/F");
        t->Branch("MTe",&MTe,"MTe/F");
        t->Branch("deta_wg",&deta_wg,"deta_wg/F");
        t->Branch("dphi_wg",&dphi_wg,"dphi_wg/F");
        t->Branch("sieieFull5x5",&sieieFull5x5,"sieieFull5x5/F");
        t->Branch("sieipFull5x5",&sieipFull5x5,"sieipFull5x5/F");
        t->Branch("sipipFull5x5",&sipipFull5x5,"sipipFull5x5/F");
        t->Branch("e1x3Full5x5",&e1x3Full5x5,"e1x3Full5x5/F");
        t->Branch("r9Full5x5",&r9Full5x5,"r9Full5x5/F");
        t->Branch("e2x2Full5x5",&e2x2Full5x5,"e2x2Full5x5/F");
        t->Branch("e2x5Full5x5",&e2x5Full5x5,"e2x5Full5x5/F");
        t->Branch("e5x5Full5x5",&e5x5Full5x5,"e5x5Full5x5/F");

        t->Branch("jetPt",&jetPt,"jetPt/F");
        t->Branch("jetEta",&jetEta,"jetEta/F");
        t->Branch("jetPhi",&jetPhi,"jetPhi/F");
        t->Branch("jetY",&jetY,"jetY/F");
        t->Branch("jetJECUnc",&jetJECUnc,"jetJECUnc/F");
        t->Branch("jetGenJetPt",&jetGenJetPt,"jetGenJetPt/F");
        t->Branch("jetGenJetEta",&jetGenJetEta,"jetGenJetEta/F");
        t->Branch("jetGenJetPhi",&jetGenJetPhi,"jetGenJetPhi/F");
        t->Branch("jetGenJetY",&jetGenJetY,"jetGenJetY/F");
        t->Branch("jetCSV2BJetTags",&jetCSV2BJetTags,"jetCSV2BJetTags/F");	
        t->Branch("jetDeepCSVTags_b",&jetDeepCSVTags_b,"jetDeepCSVTags_b/F");
        t->Branch("jetDeepCSVTags_bb",&jetDeepCSVTags_bb,"jetDeepCSVTags_bb/F");
        t->Branch("jetDeepCSVTags_c",&jetDeepCSVTags_c,"jetDeepCSVTags_c/F");
        t->Branch("jetDeepCSVTags_udsg",&jetDeepCSVTags_udsg,"jetDeepCSVTags_udsg/F");
        t->Branch("jetPartonID",&jetPartonID,"jetPartonID/I");	
        t->Branch("jetGenPartonID",	&jetGenPartonID,"jetGenPartonID/I");	
        t->Branch("jetHadFlvr",&jetHadFlvr,"jetHadFlvr/I");

        t->Branch("jetSubVtxPt",&jetSubVtxPt,"jetSubVtxPt/F");
        t->Branch("jetSubVtxMass",&jetSubVtxMass,"jetSubVtxMass/F");
        t->Branch("jetSubVtx3DVal",&jetSubVtx3DVal,"jetSubVtx3DVal/F");
        t->Branch("jetSubVtx3DErr",&jetSubVtx3DErr,"jetSubVtx3DErr/F");
        t->Branch("jetSubVtxNtrks",&jetSubVtxNtrks,"jetSubVtxNtrks/I");

        t->Branch("xsweight",&xsweight,"xsweight/F");
        t->Branch("photon_jetID",&photon_jetID,"photon_jetID/I");
        t->Branch("SeedTime",&SeedTime,"SeedTime/F");
        t->Branch("SeedEnergy",&SeedEnergy,"SeedEnergy/F");
        t->Branch("MIPTotEnergy",&MIPTotEnergy,"MIPTotEnergy/F");
        return t;
    }
    void FillEvt()
    {
        LOG_DEBUG("filling output tree event");
        t->Fill();
    }
    void Clean()
    { TTree* _t = t; memset((treeMgr*)this, 0x0, sizeof(treeMgr)); t = _t; }

    explicit treeMgr() { Clean(); }
    virtual ~treeMgr() { t->Write(); delete t; t = nullptr; }

    TTree* t;

    Int_t run;
    Long64_t event;
    Bool_t isData;
    Long64_t HLT;
    Long64_t HLTIsPrescaled;
    Long64_t HLT50ns;
    Long64_t HLTIsPrescaled50ns;
    Int_t phoFiredTrgs;
    Float_t pthat;
    Float_t genHT;
    Float_t mcPt;
    Float_t mcEta;
    Float_t mcPhi;
    Float_t mcCalIso04;
    Float_t mcTrkIso04;
    Float_t recoPt;
    Float_t recoEta;
    Float_t recoPhi;
    Float_t recoSCEta;
    Float_t r9;
    Int_t isMatched;
    Int_t isMatchedEle;
    Int_t isConverted;
    Int_t idLoose;
    Int_t idMedium;
    Int_t idTight;
    Int_t nVtx;
    Int_t nPU;
    Float_t puwei;
    Int_t eleVeto;
    Float_t HoverE;
    Float_t sieie;
    Float_t sieip;
    Float_t sipip;
    Float_t chIso;
    Float_t phoIso;
    Float_t nhIso;
    Float_t chIsoRaw;
    Float_t chWorstIso;
    Float_t phoIsoRaw;
    Float_t nhIsoRaw;
    Float_t rho;
    Float_t e1x3;
    Float_t e2x2;
    Float_t e2x5;
    Float_t e5x5;
    Float_t rawE;
    Float_t scEtaWidth;
    Float_t scPhiWidth;
    Float_t esRR;
    Float_t esEn;
    Float_t mva;
    Float_t photonIDmva;
    Int_t phoIDbit;
    Float_t mva_hgg;
    Int_t HggPresel;
    Float_t Mmm;
    Float_t Mee;
    Float_t MET;
    Int_t metFilters;
    Float_t METPhi;
    Int_t phohasPixelSeed;
    Float_t MTm;
    Float_t MTe;
    Float_t deta_wg;
    Float_t dphi_wg;
    Float_t sieieFull5x5;
    Float_t sieipFull5x5;
    Float_t sipipFull5x5;
    Float_t e1x3Full5x5;
    Float_t r9Full5x5;
    Float_t e2x2Full5x5;
    Float_t e2x5Full5x5;
    Float_t e5x5Full5x5;
    Float_t jetPt;
    Float_t jetEta;
    Float_t jetPhi;
    Float_t jetY;
    Float_t jetJECUnc;
    Float_t jetGenJetPt;
    Float_t jetGenJetEta;
    Float_t jetGenJetPhi;
    Float_t jetGenJetY;
    Float_t jetCSV2BJetTags;
    Float_t jetDeepCSVTags_b;
    Float_t jetDeepCSVTags_bb;
    Float_t jetDeepCSVTags_c;
    Float_t jetDeepCSVTags_udsg;
    Int_t jetPartonID;
    Int_t jetGenPartonID;
    Int_t jetHadFlvr;
    Float_t jetSubVtxPt;
    Float_t jetSubVtxMass;
    Float_t jetSubVtx3DVal;
    Float_t jetSubVtx3DErr;
    Int_t jetSubVtxNtrks;
    Float_t xsweight;
    Int_t photon_jetID;
    Float_t SeedTime;
    Float_t SeedEnergy;
    Float_t MIPTotEnergy;
};

#endif
