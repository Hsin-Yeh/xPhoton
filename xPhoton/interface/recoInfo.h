#ifndef __RECOINFO_H__
#define __RECOINFO_H__
#include "xPhoton/xPhoton/interface/readMgr.h"
#include "xPhoton/xPhoton/interface/PhotonSelections.h"
#include "xPhoton/xPhoton/interface/LogMgr.h"
#include "xPhoton/xPhoton/interface/MuonSelections.h"

#include <TLorentzVector.h>
#include <TMath.h>
#include <vector>
#define NOCANDFOUND -999
#define ELEIDENTIFICATION 3 // tight


struct TLorentzDATA : public TLorentzVector {
    int _idx;
    int idxInEvt() const;
    bool isZombie() const;
    TLorentzDATA();
    TLorentzDATA(int idx);
};

/*
namespace recoInfo
{


    bool JETPD_PHOTONHLT = false;
    bool ONLY_LEADINGPHOTON = false;
    bool doWmn = false;

                TLorentzDATA  buildingCandidate_jet(
                        readMgr* evtInfo,
                        int idx);
    std::vector<TLorentzDATA> buildingCandidates_jet(
            readMgr* evtInfo,
            const std::vector<int>& candIdxs);
    std::vector<TLorentzDATA> buildingCandidates_photon(
            readMgr* evtInfo,
            const std::vector<int>& candIdxs);
    std::vector<TLorentzDATA> buildingCandidates_electron(
            readMgr* evtInfo,
            const std::vector<int>& candIdxs);

    std::vector<TLorentzDATA> selectedJets_rejectphoton(readMgr* evtInfo, const TLorentzDATA& photon);
    std::vector<int> evtIdxsPassingSelection_Jets  (
            readMgr* evtInfo);
    std::vector<int> evtIdxsPassingSelection_Photons(
            readMgr* evtInfo);
    std::vector<TLorentzDATA> selectedJets(
            readMgr* evtInfo);
    std::vector<TLorentzDATA> triggeredJets(
            readMgr* evtInfo,
            bool isGJetprocess);
    std::vector<TLorentzDATA> selectedPhotons(
            readMgr* evtInfo);


    std::vector<int> electronsInEvt(readMgr* evtInfo);
    std::vector<int>     muonsInEvt(readMgr* evtInfo);
    bool isElectron ( readMgr* evtInfo, const TLorentzDATA& photon, const std::vector<TLorentzDATA>& electrons );
    bool isjetPhoton( readMgr* evtInfo, const TLorentzDATA& photon, const std::vector<TLorentzDATA>&jets );
    TLorentzDATA leadingJet(   readMgr* evtInfo, const TLorentzDATA& photon, const std::vector<TLorentzDATA>&jets );
    TLorentzDATA triggeredJet( readMgr* evtInfo, bool isGJetprocess );

    bool isEB(float eta) { return TMath::Abs(eta) < 1.4442; }
    bool isEE(float eta) { return TMath::Abs(eta) > 1.566 && TMath::Abs(eta) < 2.5; }
};
*/
#endif
