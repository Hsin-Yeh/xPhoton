#!/usr/bin/env python2
myArgs=[
      { 'reqName': 'GJet_Pt20to40_DoubleEMEnriched_MGG80toInf', 'dataset':'/GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISummer16MiniAODv3-PUMoriond17_backup_94X_mcRun2_asymptotic_v3-v1/MINIAODSIM' },
      { 'reqName': 'GJet_Pt20toInf_DoubleEMEnriched_MGG40to80', 'dataset':'/GJet_Pt-20toInf_DoubleEMEnriched_MGG-40to80_TuneCUETP8M1_13TeV_Pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3-v2/MINIAODSIM' },
      { 'reqName': 'GJet_Pt40toInf_DoubleEMEnriched_MGG80toInf', 'dataset':'/GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3-v2/MINIAODSIM' },

      # { 'reqName': 'GJet_Pt15To6000_TuneCUETHS1Flat_herwigpp', 'dataset':'/GJet_Pt-15To6000_TuneCUETHS1-Flat_13TeV_herwigpp/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3-v2/MINIAODSIM' }, # it's TuneCUETHS1Flat, not TP8M1
      { 'reqName': 'GJet_Pt15To6000_TuneCUETP8M1Flat_20M', 'dataset':'/GJet_Pt-15To6000_TuneCUETP8M1-Flat_13TeV_pythia8_20M/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3-v2/MINIAODSIM' },

]
if __name__ == '__main__':

# Usage : python crabConfig.py (to create jobs)
#         ./multicrab -c status -d <work area> (to check job status)

    for myArg in myArgs:
        from CRABAPI.RawCommand import crabCommand
        from httplib import HTTPException
        from CRABClient.UserUtilities import config
        config = config()

        from multiprocessing import Process

        # Common configuration

        config.General.workArea     = 'SentJobs_CRAB'
        config.General.transferLogs = False
        config.JobType.pluginName   = 'Analysis' # PrivateMC
        config.JobType.psetName     = 'myggNtuplier_noanalyzer.py'
        #config.JobType.inputFiles   = ['Summer16_23Sep2016V4_MC_L2Relative_AK8PFchs.txt', 'Summer16_23Sep2016V4_MC_L3Absolute_AK8PFchs.txt', 'Summer16_23Sep2016V4_MC.db']
        config.JobType.sendExternalFolder = True
        config.Data.inputDBS        = 'global'
        #config.Data.splitting       = 'LumiBased' # EventBased, FileBased, LumiBased (1 lumi ~= 300 events)
        config.Data.splitting       = 'FileBased' # EventBased, FileBased, LumiBased (1 lumi ~= 300 events)
        config.Data.totalUnits      = -1
        config.Data.publication     = False
        config.Site.storageSite     = 'T2_TW_NCHC'

        def submit(config):
            try:
                crabCommand('submit', config = config)
            except HTTPException, hte:
                print hte.headers

        # dataset dependent configuration

        config.General.requestName = myArg['reqName']
        #config.Data.unitsPerJob    = 40
        config.Data.unitsPerJob    = 1
        config.Data.inputDataset   = myArg['dataset']
        config.Data.outLFNDirBase  = '/store/user/ltsai/ggAnalysis/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic__TuneCUETP8M1_13TeV_Pythia8/'
        p = Process(target=submit, args=(config,))
        p.start()
        p.join()