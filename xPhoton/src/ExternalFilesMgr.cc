#include "xPhoton/xPhoton/interface/ExternalFilesMgr.h"
#include <stdio.h>

const char* ExternalFilesMgr::xmlFile_MVAweight(int isEndcap, int year)
{
    switch ( year )
    {
    case 2015:
        if ( isEndcap )
            return "";
        else
            return "";
    case 2016:
        if ( isEndcap )
            return "/wk_cms/ltsai/ReceivedFile/RSprocessedFiles/xmlfiles/external/spring16_80x_EE_TMVAnalysis_BDT.weights.xml";
        else
            return "/wk_cms/ltsai/ReceivedFile/RSprocessedFiles/xmlfiles/external/spring16_80x_EB_TMVAnalysis_BDT.weights.xml";
    case 2017:
        if ( isEndcap )
            return "";
        else
            return "";
    case 2018:
        if ( isEndcap )
            return "";
        else
            return "";
    default:
        return "";
    }
    return "";
}
const char* ExternalFilesMgr::RooFile_PileUp()
{
    return "/wk_cms/ltsai/ReceivedFile/RSprocessedFiles/rootfiles/external/puweights/102X/autum18/PU_histo_13TeV_2018_GoldenJSON_69200nb.root";
}
const char* ExternalFilesMgr::RooFile_ShowerShapeCorrection()
{
    //return "/wk_cms/ltsai/ReceivedFile/RSprocessedFiles/rootfiles/external/transformation_76X_v2.root";
    return "/wk_cms/ltsai/ReceivedFile/RSprocessedFiles/rootfiles/external/transformation5x5_Legacy2016_v1.root";
}

char tmpstr[200];
const char* ExternalFilesMgr::testchar()
{
    return "kkk";
    sprintf(tmpstr, "hiii");
    return tmpstr;
}

