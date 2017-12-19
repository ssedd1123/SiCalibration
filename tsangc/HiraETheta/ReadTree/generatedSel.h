/////////////////////////////////////////////////////////////////////////
//   This class has been automatically generated 
//   (at Tue Dec 12 21:10:51 2017 by ROOT version 6.04/02)
//   from TTree E16042/Physics event items:  RBExperiment TTree
//   found on file: root-00010-00.root
/////////////////////////////////////////////////////////////////////////


#ifndef generatedSel_h
#define generatedSel_h

// System Headers needed by the proxy
#if defined(__CINT__) && !defined(__MAKECINT__)
   #define ROOT_Rtypes
   #define ROOT_TError
#endif
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TPad.h>
#include <TH1.h>
#include <TSelector.h>
#include <TBranchProxy.h>
#include <TBranchProxyDirector.h>
#include <TBranchProxyTemplate.h>
#include <TFriendProxy.h>
using namespace ROOT;

// forward declarations needed by this particular proxy
class TClonesArray;
class TObject;
class RBHiRATelescope;
class TNamed;
class TString;
class RBDetector;
class RBHiRASiDet;
class RBHiRACsI;


// Header needed by this particular proxy
#include "TClonesArray.h"
#include "TObject.h"
#include "RBHiRATelescope.h"
#include "TNamed.h"
#include "TString.h"
#include "RBDetector.h"
#include <vector>
#include "RBHiRASiDet.h"
#include "RBHiRACsI.h"


class Proxy_Interface {
   // This class defines the list of methods that are directly used by generatedSel,
   // and that can be overloaded in the user's script
public:
   void Proxy_Begin(TTree*) {}
   void Proxy_SlaveBegin(TTree*) {}
   Bool_t Proxy_Notify() { return kTRUE; }
   Bool_t Proxy_Process(Long64_t) { return kTRUE; }
   void Proxy_SlaveTerminate() {}
   void Proxy_Terminate() {}
};


class generatedSel : public TSelector, public Proxy_Interface {
public :
   TTree          *fChain;         //!pointer to the analyzed TTree or TChain
   TH1            *htemp;          //!pointer to the histogram
   TBranchProxyDirector fDirector; //!Manages the proxys

   // Optional User methods
   TClass         *fClass;    // Pointer to this class's description

   // Wrapper class for each unwounded class
   struct TClaPx_TObject
   {
      TClaPx_TObject(TBranchProxyDirector* director,const char *top,const char *mid=0) :
         ffPrefix       (top,mid),
         obj            (director, top, mid),
         fUniqueID      (director, ffPrefix, "fUniqueID"),
         fBits          (director, ffPrefix, "fBits")
      {};
      TClaPx_TObject(TBranchProxyDirector* director, TBranchProxy *parent, const char *membername, const char *top=0, const char *mid=0) :
         ffPrefix       (top,mid),
         obj            (director, parent, membername),
         fUniqueID      (director, ffPrefix, "fUniqueID"),
         fBits          (director, ffPrefix, "fBits")
      {};
      TBranchProxyHelper ffPrefix;
      InjecTBranchProxyInterface();
      const TObject* operator[](Int_t i) { return obj.At(i); }
      const TObject* operator[](UInt_t i) { return obj.At(i); }
      Int_t GetEntries() { return obj.GetEntries(); }
      const TClonesArray* operator->() { return obj.GetPtr(); }
      TClaObjProxy<TObject > obj;

      TClaUIntProxy   fUniqueID;
      TClaUIntProxy   fBits;
   };
   struct TClaPx_RBHINPHit
      : public TClaPx_TObject
   {
      TClaPx_RBHINPHit(TBranchProxyDirector* director,const char *top,const char *mid=0) :
         TClaPx_TObject   (director, top, mid),
         ffPrefix         (top,mid),
         obj              (director, top, mid),
         fXLMIndex        (director, ffPrefix, "fXLMIndex"),
         fBank            (director, ffPrefix, "fBank"),
         fGlobalBank      (director, ffPrefix, "fGlobalBank"),
         fChMismatch      (director, ffPrefix, "fChMismatch"),
         fChannel         (director, ffPrefix, "fChannel"),
         fChip            (director, ffPrefix, "fChip"),
         fEnergyHi        (director, ffPrefix, "fEnergyHi"),
         fEnergyLo        (director, ffPrefix, "fEnergyLo"),
         fTime            (director, ffPrefix, "fTime")
      {};
      TClaPx_RBHINPHit(TBranchProxyDirector* director, TBranchProxy *parent, const char *membername, const char *top=0, const char *mid=0) :
         TClaPx_TObject   (director, parent, membername),
         ffPrefix         (top,mid),
         obj              (director, parent, membername),
         fXLMIndex        (director, ffPrefix, "fXLMIndex"),
         fBank            (director, ffPrefix, "fBank"),
         fGlobalBank      (director, ffPrefix, "fGlobalBank"),
         fChMismatch      (director, ffPrefix, "fChMismatch"),
         fChannel         (director, ffPrefix, "fChannel"),
         fChip            (director, ffPrefix, "fChip"),
         fEnergyHi        (director, ffPrefix, "fEnergyHi"),
         fEnergyLo        (director, ffPrefix, "fEnergyLo"),
         fTime            (director, ffPrefix, "fTime")
      {};
      TBranchProxyHelper ffPrefix;
      InjecTBranchProxyInterface();
      Int_t GetEntries() { return obj.GetEntries(); }
      const TClonesArray* operator->() { return obj.GetPtr(); }
      TClaProxy obj;

      TClaUShortProxy   fXLMIndex;
      TClaUShortProxy   fBank;
      TClaUShortProxy   fGlobalBank;
      TClaBoolProxy     fChMismatch;
      TClaUShortProxy   fChannel;
      TClaUShortProxy   fChip;
      TClaUShortProxy   fEnergyHi;
      TClaUShortProxy   fEnergyLo;
      TClaUShortProxy   fTime;
   };
   struct TPx_TObject
   {
      TPx_TObject(TBranchProxyDirector* director,const char *top,const char *mid=0) :
         ffPrefix    (top,mid),
         obj         (director, top, mid),
         fUniqueID   (director, obj.GetProxy(), "fUniqueID"),
         fBits       (director, obj.GetProxy(), "fBits")
      {};
      TPx_TObject(TBranchProxyDirector* director, TBranchProxy *parent, const char *membername, const char *top=0, const char *mid=0) :
         ffPrefix    (top,mid),
         obj         (director, parent, membername),
         fUniqueID   (director, obj.GetProxy(), "fUniqueID"),
         fBits       (director, obj.GetProxy(), "fBits")
      {};
      TBranchProxyHelper ffPrefix;
      InjecTBranchProxyInterface();
      const TObject* operator->() { return obj.GetPtr(); }
      TObjProxy<TObject > obj;

      TUIntProxy   fUniqueID;
      TUIntProxy   fBits;
   };
   struct TPx_TNamed
      : public TPx_TObject
   {
      TPx_TNamed(TBranchProxyDirector* director,const char *top,const char *mid=0) :
         TPx_TObject          (director, top, mid),
         ffPrefix             (top,mid),
         obj                  (director, top, mid),
         fName                (director, obj.GetProxy(), "fName"),
         fTitle               (director, obj.GetProxy(), "fTitle")
      {};
      TPx_TNamed(TBranchProxyDirector* director, TBranchProxy *parent, const char *membername, const char *top=0, const char *mid=0) :
         TPx_TObject          (director, parent, membername),
         ffPrefix             (top,mid),
         obj                  (director, parent, membername),
         fName                (director, obj.GetProxy(), "fName"),
         fTitle               (director, obj.GetProxy(), "fTitle")
      {};
      TBranchProxyHelper    ffPrefix;
      InjecTBranchProxyInterface();
      const TNamed* operator->() { return obj.GetPtr(); }
      TObjProxy<TNamed > obj;

      TObjProxy<TString >   fName;
      TObjProxy<TString >   fTitle;
   };
   struct TPx_TNamed_1
      : public TObjProxy<TObject >
   {
      TPx_TNamed_1(TBranchProxyDirector* director,const char *top,const char *mid=0) :
         TObjProxy<TObject >  (director, top, mid),
         ffPrefix             (top,mid),
         obj                  (director, top, mid),
         fName                (director, obj.GetProxy(), "fName"),
         fTitle               (director, obj.GetProxy(), "fTitle")
      {};
      TPx_TNamed_1(TBranchProxyDirector* director, TBranchProxy *parent, const char *membername, const char *top=0, const char *mid=0) :
         TObjProxy<TObject >  (director, parent, membername),
         ffPrefix             (top,mid),
         obj                  (director, parent, membername),
         fName                (director, obj.GetProxy(), "fName"),
         fTitle               (director, obj.GetProxy(), "fTitle")
      {};
      TBranchProxyHelper    ffPrefix;
      InjecTBranchProxyInterface();
      const TNamed* operator->() { return obj.GetPtr(); }
      TObjProxy<TNamed > obj;

      TObjProxy<TString >   fName;
      TObjProxy<TString >   fTitle;
   };
   struct TPx_RBDetector
      : public TPx_TNamed_1
   {
      TPx_RBDetector(TBranchProxyDirector* director,const char *top,const char *mid=0) :
         TPx_TNamed_1(director, top, mid),
         ffPrefix(top,mid),
         obj(director, top, mid)
      {};
      TPx_RBDetector(TBranchProxyDirector* director, TBranchProxy *parent, const char *membername, const char *top=0, const char *mid=0) :
         TPx_TNamed_1(director, parent, membername),
         ffPrefix(top,mid),
         obj(director, parent, membername)
      {};
      TBranchProxyHelper ffPrefix;
      InjecTBranchProxyInterface();
      TBranchProxy obj;

   };
   struct TPx_RBHiRATelescope
      : public TObjProxy<RBDetector >
   {
      TPx_RBHiRATelescope(TBranchProxyDirector* director,const char *top,const char *mid=0) :
         TObjProxy<RBDetector >   (director, top, mid),
         ffPrefix                 (top,mid),
         obj                      (director, top, mid),
         fHits                    (director, "fHits"),
         DE                       (director, "DE"),
         EF                       (director, "EF"),
         EB                       (director, "EB"),
         CsI                      (director, "CsI")
      {};
      TPx_RBHiRATelescope(TBranchProxyDirector* director, TBranchProxy *parent, const char *membername, const char *top=0, const char *mid=0) :
         TObjProxy<RBDetector >   (director, parent, membername),
         ffPrefix                 (top,mid),
         obj                      (director, parent, membername),
         fHits                    (director, "fHits"),
         DE                       (director, "DE"),
         EF                       (director, "EF"),
         EB                       (director, "EB"),
         CsI                      (director, "CsI")
      {};
      TBranchProxyHelper        ffPrefix;
      InjecTBranchProxyInterface();
      TBranchProxy obj;

      TIntProxy                 fHits;
      TObjProxy<RBHiRASiDet >   DE;
      TObjProxy<RBHiRASiDet >   EF;
      TObjProxy<RBHiRASiDet >   EB;
      TObjProxy<RBHiRACsI >     CsI;
   };

   // Proxy for each of the branches, leaves and friends of the tree
   TUIntProxy                fBRI_Size;
   TULong64Proxy             fBRI_Timestamp;
   TClaPx_RBHINPHit          RBHINPUnpacker_fHits;
   TClaPx_TObject            baseTObject;
   TClaUShortProxy           fXLMIndex;
   TClaUShortProxy           fBank;
   TClaUShortProxy           fGlobalBank;
   TClaBoolProxy             fChMismatch;
   TClaUShortProxy           fChannel;
   TClaUShortProxy           fChip;
   TClaUShortProxy           fEnergyHi;
   TClaUShortProxy           fEnergyLo;
   TClaUShortProxy           fTime;
   TArrayUShortProxy         adc1;
   TArrayUShortProxy         adc2;
   TArrayUShortProxy         tdc1;
   TUShortProxy              fNwords;
   TUShortProxy              fErrorCode;
   TShortProxy               fRawMult;
   TArrayShortProxy          fHits;
   TPx_RBHiRATelescope       tele0;
   TObjProxy<RBDetector >    baseRBDetector;
   TObjProxy<RBHiRASiDet >   DE;
   TObjProxy<RBHiRASiDet >   EF;
   TObjProxy<RBHiRASiDet >   EB;
   TObjProxy<RBHiRACsI >     CsI;
   TPx_RBHiRATelescope       tele1;
   TPx_RBHiRATelescope       tele2;
   TPx_RBHiRATelescope       tele3;
   TPx_RBHiRATelescope       tele4;
   TPx_RBHiRATelescope       tele5;
   TPx_RBHiRATelescope       tele6;
   TPx_RBHiRATelescope       tele7;
   TPx_RBHiRATelescope       tele8;
   TPx_RBHiRATelescope       tele9;
   TPx_RBHiRATelescope       tele10;
   TPx_RBHiRATelescope       tele11;


   generatedSel(TTree *tree=0) : 
      fChain(0),
      htemp(0),
      fDirector(tree,-1),
      fClass                (TClass::GetClass("generatedSel")),
      fBRI_Size                (&fDirector,"fBRI_Size"),
      fBRI_Timestamp           (&fDirector,"fBRI_Timestamp"),
      RBHINPUnpacker_fHits     (&fDirector,"RBHINPUnpacker.fHits"),
      baseTObject              (&fDirector,"RBHINPUnpacker.fHits"),
      fXLMIndex                (&fDirector,"RBHINPUnpacker.fHits.fXLMIndex"),
      fBank                    (&fDirector,"RBHINPUnpacker.fHits.fBank"),
      fGlobalBank              (&fDirector,"RBHINPUnpacker.fHits.fGlobalBank"),
      fChMismatch              (&fDirector,"RBHINPUnpacker.fHits.fChMismatch"),
      fChannel                 (&fDirector,"RBHINPUnpacker.fHits.fChannel"),
      fChip                    (&fDirector,"RBHINPUnpacker.fHits.fChip"),
      fEnergyHi                (&fDirector,"RBHINPUnpacker.fHits.fEnergyHi"),
      fEnergyLo                (&fDirector,"RBHINPUnpacker.fHits.fEnergyLo"),
      fTime                    (&fDirector,"RBHINPUnpacker.fHits.fTime"),
      adc1                     (&fDirector,"adc1"),
      adc2                     (&fDirector,"adc2"),
      tdc1                     (&fDirector,"tdc1"),
      fNwords                  (&fDirector,"hira.fNwords"),
      fErrorCode               (&fDirector,"hira.fErrorCode"),
      fRawMult                 (&fDirector,"hira.fRawMult"),
      fHits                    (&fDirector,"hira.fHits"),
      tele0                    (&fDirector,"tele0"),
      baseRBDetector           (&fDirector,"RBDetector"),
      DE                       (&fDirector,"DE"),
      EF                       (&fDirector,"EF"),
      EB                       (&fDirector,"EB"),
      CsI                      (&fDirector,"CsI"),
      tele1                    (&fDirector,"tele1"),
      tele2                    (&fDirector,"tele2"),
      tele3                    (&fDirector,"tele3"),
      tele4                    (&fDirector,"tele4"),
      tele5                    (&fDirector,"tele5"),
      tele6                    (&fDirector,"tele6"),
      tele7                    (&fDirector,"tele7"),
      tele8                    (&fDirector,"tele8"),
      tele9                    (&fDirector,"tele9"),
      tele10                   (&fDirector,"tele10"),
      tele11                   (&fDirector,"tele11")
      { }
   ~generatedSel();
   Int_t   Version() const {return 1;}
   void    Begin(::TTree *tree);
   void    SlaveBegin(::TTree *tree);
   void    Init(::TTree *tree);
   Bool_t  Notify();
   Bool_t  Process(Long64_t entry);
   void    SlaveTerminate();
   void    Terminate();

   ClassDef(generatedSel,0);


//inject the user's code
#include "Proxy.cxx"
};

#endif


#ifdef __MAKECINT__
#pragma link C++ class generatedSel::TClaPx_TObject-;
#pragma link C++ class generatedSel::TClaPx_RBHINPHit-;
#pragma link C++ class generatedSel::TPx_TObject-;
#pragma link C++ class generatedSel::TPx_TNamed-;
#pragma link C++ class generatedSel::TPx_TNamed_1-;
#pragma link C++ class generatedSel::TPx_RBDetector-;
#pragma link C++ class generatedSel::TPx_RBHiRATelescope-;
#pragma link C++ class generatedSel;
#endif


inline generatedSel::~generatedSel() {
   // destructor. Clean up helpers.

}

inline void generatedSel::Init(TTree *tree)
{
//   Set branch addresses
   if (tree == 0) return;
   fChain = tree;
   fDirector.SetTree(fChain);
   if (htemp == 0) {
      htemp = fDirector.CreateHistogram(GetOption());
      htemp->SetTitle("Proxy.cxx");
      fObject = htemp;
   }
}

Bool_t generatedSel::Notify()
{
   // Called when loading a new file.
   // Get branch pointers.
   fDirector.SetTree(fChain);
   Proxy_Notify();
   
   return kTRUE;
}
   

inline void generatedSel::Begin(TTree *tree)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   Proxy_Begin(tree);

}

inline void generatedSel::SlaveBegin(TTree *tree)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   Init(tree);

   Proxy_SlaveBegin(tree);

}

inline Bool_t generatedSel::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either TTree::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.

   // WARNING when a selector is used with a TChain, you must use
   //  the pointer to the current TTree to call GetEntry(entry).
   //  The entry is always the local entry number in the current tree.
   //  Assuming that fChain is the pointer to the TChain being processed,
   //  use fChain->GetTree()->GetEntry(entry).


   fDirector.SetReadEntry(entry);
   htemp->Fill(Proxy());
   Proxy_Process(entry);
   return kTRUE;

}

inline void generatedSel::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.
   Proxy_SlaveTerminate();
}

inline void generatedSel::Terminate()
{
   // Function called at the end of the event loop.
   htemp = (TH1*)fObject;
   Int_t drawflag = (htemp && htemp->GetEntries()>0);
   
   if (gPad && !drawflag && !fOption.Contains("goff") && !fOption.Contains("same")) {
      gPad->Clear();
   } else {
      if (fOption.Contains("goff")) drawflag = false;
      if (drawflag) htemp->Draw(fOption);
   }
   Proxy_Terminate();
}
