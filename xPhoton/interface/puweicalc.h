/* Class which calculates event weights for MC due to difference in pileup
 * distributions between data and MC.
 */

#ifndef PUWEICALC_H
#define PUWEICALC_H

#include <map>
#include <TH1D.h>

// prints a message and exits gracefully
#ifndef FATAL
#define FATAL(msg) do { fprintf(stderr, "FATAL: %s\n", msg); gSystem->Exit(1); } while (0)
#endif

class PUWeightCalculator {
 public:
   virtual ~PUWeightCalculator();

   void Init(const char* path);
   double GetWeight(Int_t run, float puTrue);

 protected:
   std::map<Int_t,TH1*> fRunHistoMap;  // {run number: weights} map
};

#endif
