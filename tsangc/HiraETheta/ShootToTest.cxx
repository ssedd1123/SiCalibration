#include "HiraParser.h"
#include "HiraTransformation.h"
#include "TRandom3.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TText.h"
#include <string>
#include <sstream>

std::string to_string(int t_x)
{
	std::stringstream ss;
	ss << t_x;
	return ss.str();
}

void ShootToTest()
{
	TH2F *hist = new TH2F("th2f", "coverage", 1000,-200,250,1000, -250, 120);
	TRandom3 gRandom;
	const double size_x = 64., size_y = 64.;

	TCanvas *c1 = new TCanvas;
	HiraParser parser("hiraU_cal_final_orphans_5.detector");
	hist->Draw();
	while(parser.FindNextDetector("HiraTelescope"))
	{
		HiraTransformation hira(parser.GetTVector3("B"), parser.GetTVector3("C"), parser.GetTVector3("D"), parser.GetTVector3("A"));

		for(int i = 0; i < 10000; ++i)
		{
			TVector3 result = hira.TransformStripNum(
						int(gRandom.Uniform(0, 32)),
						int(gRandom.Uniform(0, 32)));
			hist->Fill(result[0], result[1]);
		}
		TVector3 result = hira.TransformStripNum(0,0);
		TText *text = new TText(result[0], result[1], ("Tele_" + to_string(parser.GetValue<int>("Tele_no"))).c_str());
		text->Draw("same");
	}
	hist->Draw("same");
	c1->SaveAs("~/test.png");
}
