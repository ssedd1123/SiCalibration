//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Dec 12 21:21:17 2017 by ROOT version 6.04/02
// from TTree E16042/Physics event items:  RBExperiment TTree
// found on file: root-00010-00.root
//////////////////////////////////////////////////////////

#ifndef E16042_h
#define E16042_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"

class E16042 : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxRBHINPUnpacker_fHits = 768;

   // Declaration of leaf types
   UInt_t          fBRI_Size;
   ULong64_t       fBRI_Timestamp;
   Int_t           RBHINPUnpacker_fHits_;
   UInt_t          RBHINPUnpacker_fHits_fUniqueID[kMaxRBHINPUnpacker_fHits];   //[RBHINPUnpacker.fHits_]
   UInt_t          RBHINPUnpacker_fHits_fBits[kMaxRBHINPUnpacker_fHits];   //[RBHINPUnpacker.fHits_]
   UShort_t        RBHINPUnpacker_fHits_fXLMIndex[kMaxRBHINPUnpacker_fHits];   //[RBHINPUnpacker.fHits_]
   UShort_t        RBHINPUnpacker_fHits_fBank[kMaxRBHINPUnpacker_fHits];   //[RBHINPUnpacker.fHits_]
   UShort_t        RBHINPUnpacker_fHits_fGlobalBank[kMaxRBHINPUnpacker_fHits];   //[RBHINPUnpacker.fHits_]
   Bool_t          RBHINPUnpacker_fHits_fChMismatch[kMaxRBHINPUnpacker_fHits];   //[RBHINPUnpacker.fHits_]
   UShort_t        RBHINPUnpacker_fHits_fChannel[kMaxRBHINPUnpacker_fHits];   //[RBHINPUnpacker.fHits_]
   UShort_t        RBHINPUnpacker_fHits_fChip[kMaxRBHINPUnpacker_fHits];   //[RBHINPUnpacker.fHits_]
   UShort_t        RBHINPUnpacker_fHits_fEnergyHi[kMaxRBHINPUnpacker_fHits];   //[RBHINPUnpacker.fHits_]
   UShort_t        RBHINPUnpacker_fHits_fEnergyLo[kMaxRBHINPUnpacker_fHits];   //[RBHINPUnpacker.fHits_]
   UShort_t        RBHINPUnpacker_fHits_fTime[kMaxRBHINPUnpacker_fHits];   //[RBHINPUnpacker.fHits_]
   UShort_t        adc1[32];
   UShort_t        adc2[32];
   UShort_t        tdc1[128];
   UShort_t        hira_fNwords;
   UShort_t        hira_fErrorCode;
   Short_t         hira_fRawMult;
   Short_t         hira_fHits[5];
 //RBHiRATelescope *tele0;
 //RBHiRATelescope *RBDetector;
   Int_t           fHits;
 //RBHiRASiDet     DE;
 //RBHiRASiDet     EF;
 //RBHiRASiDet     EB;
 //RBHiRACsI       CsI;
 //RBHiRATelescope *tele1;
 //RBHiRATelescope *RBDetector;
   Int_t           fHits;
 //RBHiRASiDet     DE;
 //RBHiRASiDet     EF;
 //RBHiRASiDet     EB;
 //RBHiRACsI       CsI;
 //RBHiRATelescope *tele2;
 //RBHiRATelescope *RBDetector;
   Int_t           fHits;
 //RBHiRASiDet     DE;
 //RBHiRASiDet     EF;
 //RBHiRASiDet     EB;
 //RBHiRACsI       CsI;
 //RBHiRATelescope *tele3;
 //RBHiRATelescope *RBDetector;
   Int_t           fHits;
 //RBHiRASiDet     DE;
 //RBHiRASiDet     EF;
 //RBHiRASiDet     EB;
 //RBHiRACsI       CsI;
 //RBHiRATelescope *tele4;
 //RBHiRATelescope *RBDetector;
   Int_t           fHits;
 //RBHiRASiDet     DE;
 //RBHiRASiDet     EF;
 //RBHiRASiDet     EB;
 //RBHiRACsI       CsI;
 //RBHiRATelescope *tele5;
 //RBHiRATelescope *RBDetector;
   Int_t           fHits;
 //RBHiRASiDet     DE;
 //RBHiRASiDet     EF;
 //RBHiRASiDet     EB;
 //RBHiRACsI       CsI;
 //RBHiRATelescope *tele6;
 //RBHiRATelescope *RBDetector;
   Int_t           fHits;
 //RBHiRASiDet     DE;
 //RBHiRASiDet     EF;
 //RBHiRASiDet     EB;
 //RBHiRACsI       CsI;
 //RBHiRATelescope *tele7;
 //RBHiRATelescope *RBDetector;
   Int_t           fHits;
 //RBHiRASiDet     DE;
 //RBHiRASiDet     EF;
 //RBHiRASiDet     EB;
 //RBHiRACsI       CsI;
 //RBHiRATelescope *tele8;
 //RBHiRATelescope *RBDetector;
   Int_t           fHits;
 //RBHiRASiDet     DE;
 //RBHiRASiDet     EF;
 //RBHiRASiDet     EB;
 //RBHiRACsI       CsI;
 //RBHiRATelescope *tele9;
 //RBHiRATelescope *RBDetector;
   Int_t           fHits;
 //RBHiRASiDet     DE;
 //RBHiRASiDet     EF;
 //RBHiRASiDet     EB;
 //RBHiRACsI       CsI;
 //RBHiRATelescope *tele10;
 //RBHiRATelescope *RBDetector;
   Int_t           fHits;
 //RBHiRASiDet     DE;
 //RBHiRASiDet     EF;
 //RBHiRASiDet     EB;
 //RBHiRACsI       CsI;
 //RBHiRATelescope *tele11;
 //RBHiRATelescope *RBDetector;
   Int_t           fHits;
 //RBHiRASiDet     DE;
 //RBHiRASiDet     EF;
 //RBHiRASiDet     EB;
 //RBHiRACsI       CsI;

   // List of branches
   TBranch        *b_fBRI_Size;   //!
   TBranch        *b_fBRI_Timestamp;   //!
   TBranch        *b_RBHINPUnpacker_fHits_;   //!
   TBranch        *b_RBHINPUnpacker_fHits_fUniqueID;   //!
   TBranch        *b_RBHINPUnpacker_fHits_fBits;   //!
   TBranch        *b_RBHINPUnpacker_fHits_fXLMIndex;   //!
   TBranch        *b_RBHINPUnpacker_fHits_fBank;   //!
   TBranch        *b_RBHINPUnpacker_fHits_fGlobalBank;   //!
   TBranch        *b_RBHINPUnpacker_fHits_fChMismatch;   //!
   TBranch        *b_RBHINPUnpacker_fHits_fChannel;   //!
   TBranch        *b_RBHINPUnpacker_fHits_fChip;   //!
   TBranch        *b_RBHINPUnpacker_fHits_fEnergyHi;   //!
   TBranch        *b_RBHINPUnpacker_fHits_fEnergyLo;   //!
   TBranch        *b_RBHINPUnpacker_fHits_fTime;   //!
   TBranch        *b_adc1;   //!
   TBranch        *b_adc2;   //!
   TBranch        *b_tdc1;   //!
   TBranch        *b_fNwords;   //!
   TBranch        *b_fErrorCode;   //!
   TBranch        *b_fRawMult;   //!
   TBranch        *b_fHits;   //!
   TBranch        *b_tele0_fHits;   //!
   TBranch        *b_tele1_fHits;   //!
   TBranch        *b_tele2_fHits;   //!
   TBranch        *b_tele3_fHits;   //!
   TBranch        *b_tele4_fHits;   //!
   TBranch        *b_tele5_fHits;   //!
   TBranch        *b_tele6_fHits;   //!
   TBranch        *b_tele7_fHits;   //!
   TBranch        *b_tele8_fHits;   //!
   TBranch        *b_tele9_fHits;   //!
   TBranch        *b_tele10_fHits;   //!
   TBranch        *b_tele11_fHits;   //!

   E16042(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~E16042() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(E16042,0);
};

#endif

#ifdef E16042_cxx
void E16042::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("fBRI_Size", &fBRI_Size, &b_fBRI_Size);
   fChain->SetBranchAddress("fBRI_Timestamp", &fBRI_Timestamp, &b_fBRI_Timestamp);
   fChain->SetBranchAddress("RBHINPUnpacker.fHits", &RBHINPUnpacker_fHits_, &b_RBHINPUnpacker_fHits_);
   fChain->SetBranchAddress("RBHINPUnpacker.fHits.fUniqueID", RBHINPUnpacker_fHits_fUniqueID, &b_RBHINPUnpacker_fHits_fUniqueID);
   fChain->SetBranchAddress("RBHINPUnpacker.fHits.fBits", RBHINPUnpacker_fHits_fBits, &b_RBHINPUnpacker_fHits_fBits);
   fChain->SetBranchAddress("RBHINPUnpacker.fHits.fXLMIndex", RBHINPUnpacker_fHits_fXLMIndex, &b_RBHINPUnpacker_fHits_fXLMIndex);
   fChain->SetBranchAddress("RBHINPUnpacker.fHits.fBank", RBHINPUnpacker_fHits_fBank, &b_RBHINPUnpacker_fHits_fBank);
   fChain->SetBranchAddress("RBHINPUnpacker.fHits.fGlobalBank", RBHINPUnpacker_fHits_fGlobalBank, &b_RBHINPUnpacker_fHits_fGlobalBank);
   fChain->SetBranchAddress("RBHINPUnpacker.fHits.fChMismatch", RBHINPUnpacker_fHits_fChMismatch, &b_RBHINPUnpacker_fHits_fChMismatch);
   fChain->SetBranchAddress("RBHINPUnpacker.fHits.fChannel", RBHINPUnpacker_fHits_fChannel, &b_RBHINPUnpacker_fHits_fChannel);
   fChain->SetBranchAddress("RBHINPUnpacker.fHits.fChip", RBHINPUnpacker_fHits_fChip, &b_RBHINPUnpacker_fHits_fChip);
   fChain->SetBranchAddress("RBHINPUnpacker.fHits.fEnergyHi", RBHINPUnpacker_fHits_fEnergyHi, &b_RBHINPUnpacker_fHits_fEnergyHi);
   fChain->SetBranchAddress("RBHINPUnpacker.fHits.fEnergyLo", RBHINPUnpacker_fHits_fEnergyLo, &b_RBHINPUnpacker_fHits_fEnergyLo);
   fChain->SetBranchAddress("RBHINPUnpacker.fHits.fTime", RBHINPUnpacker_fHits_fTime, &b_RBHINPUnpacker_fHits_fTime);
   fChain->SetBranchAddress("adc1", adc1, &b_adc1);
   fChain->SetBranchAddress("adc2", adc2, &b_adc2);
   fChain->SetBranchAddress("tdc1", tdc1, &b_tdc1);
   fChain->SetBranchAddress("hira.fNwords", &hira_fNwords, &b_fNwords);
   fChain->SetBranchAddress("hira.fErrorCode", &hira_fErrorCode, &b_fErrorCode);
   fChain->SetBranchAddress("hira.fRawMult", &hira_fRawMult, &b_fRawMult);
   fChain->SetBranchAddress("hira.fHits", hira_fHits, &b_fHits);
   fChain->SetBranchAddress("fHits", &fHits, &b_tele0_fHits);
//    fChain->SetBranchAddress("fHits", &fHits, &b_tele1_fHits);
//    fChain->SetBranchAddress("fHits", &fHits, &b_tele2_fHits);
//    fChain->SetBranchAddress("fHits", &fHits, &b_tele3_fHits);
//    fChain->SetBranchAddress("fHits", &fHits, &b_tele4_fHits);
//    fChain->SetBranchAddress("fHits", &fHits, &b_tele5_fHits);
//    fChain->SetBranchAddress("fHits", &fHits, &b_tele6_fHits);
//    fChain->SetBranchAddress("fHits", &fHits, &b_tele7_fHits);
//    fChain->SetBranchAddress("fHits", &fHits, &b_tele8_fHits);
//    fChain->SetBranchAddress("fHits", &fHits, &b_tele9_fHits);
//    fChain->SetBranchAddress("fHits", &fHits, &b_tele10_fHits);
//    fChain->SetBranchAddress("fHits", &fHits, &b_tele11_fHits);
}

Bool_t E16042::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef E16042_cxx
