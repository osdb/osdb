/*************************************************************************
 * This file is part of OSDB.                                            *
 *                                                                       *
 * OSDB is free software: you can redistribute it and/or modify          *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * OSDB is distributed in the hope that it will be useful,               *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with OSDB.  If not, see <http://www.gnu.org/licenses/>.         *
 *************************************************************************/

#ifndef AS3APSUITE_CPP_
#define AS3APSUITE_CPP_

#include "../BenchmarkSuite.h"

#include "AggCreateView.cpp"
#include "AggFunc.cpp"
#include "AggInfoRetrieval.cpp"
#include "AggScal.cpp"
//#include "AggSimpleReport.cpp"
#include "AggSubtotalReport.cpp"
#include "AggTotalReport.cpp"
#include "BulkAppend.cpp"
#include "BulkDelete.cpp"
#include "BulkModify.cpp"
#include "BulkSave.cpp"
#include "CountTuples.cpp"
#include "CreateIdxHundredCodeBt.cpp"
#include "CreateIdxHundredCodeH.cpp"
#include "CreateIdxHundredKeyBt.cpp"
#include "CreateIdxTenpctCodeH.cpp"
#include "CreateIdxTenpctDecimBt.cpp"
#include "CreateIdxTenpctDoubleBt.cpp"
#include "CreateIdxTenpctFloatBt.cpp"
#include "CreateIdxTenpctIntBt.cpp"
#include "CreateIdxTenpctKeyBt.cpp"
#include "CreateIdxTenpctKeyCodeBt.cpp"
#include "CreateIdxTenpctNameH.cpp"
#include "CreateIdxTenpctSignedBt.cpp"
#include "CreateIdxTinyKeyBt.cpp"
#include "CreateIdxUniquesCodeH.cpp"
#include "CreateIdxUniquesKeyBt.cpp"
#include "CreateIdxUpdatesCodeH.cpp"
#include "CreateIdxUpdatesDecimBt.cpp"
#include "CreateIdxUpdatesDoubleBt.cpp"
#include "CreateIdxUpdatesIntBt.cpp"
#include "CreateIdxUpdatesKeyBt.cpp"
#include "Join2.cpp"
#include "Join2Cl.cpp"
#include "Join3Cl.cpp"
#include "Join3Ncl.cpp"
#include "Join4Cl.cpp"
#include "Join4Ncl.cpp"
//#include "MuCheckmod100Rand.cpp"
//#include "MuCheckmod100Seq.cpp"
//#include "MuMod100Rand.cpp"
//#include "MuOltpUpdate.cpp"
//#include "MuUnmod100Rand.cpp"
//#include "MuUnmod100Seq.cpp"
#include "Proj100.cpp"
#include "Proj10Pct.cpp"
#include "Sel100Cl.cpp"
#include "Sel100Ncl.cpp"
#include "Sel10PctNcl.cpp"
#include "Sel1Cl.cpp"
#include "SelVariableSelectHigh.cpp"
#include "SelVariableSelectLow.cpp"
#include "TableScan.cpp"
#include "UpdAppendDuplicate.cpp"
#include "UpdAppTEnd.cpp"
#include "UpdAppTMid.cpp"
#include "UpdDelTEnd.cpp"
#include "UpdDelTMid.cpp"
#include "UpdIntegrityTest.cpp"
#include "UpdModTCod.cpp"
#include "UpdModTEnd.cpp"
#include "UpdModTInt.cpp"
#include "UpdModTMid.cpp"
#include "UpdRemoveDuplicate.cpp"


class AS3APSuite : public BenchmarkSuite
{
public:
	AS3APSuite(Database& database, Logger& logger) :
		BenchmarkSuite("AS3AP_Suite", database, logger)
	{
		addTest(new AggCreateView(database, logger));
		addTest(new AggFunc(database, logger));
		addTest(new AggInfoRetrieval(database, logger));
		addTest(new AggScal(database, logger));
//		addTest(new AggSimpleReport(database, logger)); // Ignore - query takes a long time (under investigation)
		addTest(new AggSubtotalReport(database, logger));
		addTest(new AggTotalReport(database, logger));
		addTest(new BulkAppend(database, logger));
		addTest(new BulkDelete(database, logger));
		addTest(new BulkModify(database, logger));
		addTest(new BulkSave(database, logger));
		addTest(new CountTuples(database, logger));
//		addTest(new CreateIdxHundredCodeBt(database, logger)); // BTREE indexes disabled for now since MySQL does not support them - need to find a better solution
		addTest(new CreateIdxHundredCodeH(database, logger));
//		addTest(new CreateIdxHundredKeyBt(database, logger));
		addTest(new CreateIdxTenpctCodeH(database, logger));
//		addTest(new CreateIdxTenpctDecimBt(database, logger));
//		addTest(new CreateIdxTenpctDoubleBt(database, logger));
//		addTest(new CreateIdxTenpctFloatBt(database, logger));
//		addTest(new CreateIdxTenpctIntBt(database, logger));
//		addTest(new CreateIdxTenpctKeyBt(database, logger));
//		addTest(new CreateIdxTenpctKeyCodeBt(database, logger));
		addTest(new CreateIdxTenpctNameH(database, logger));
//		addTest(new CreateIdxTenpctSignedBt(database, logger));
//		addTest(new CreateIdxTinyKeyBt(database, logger));
		addTest(new CreateIdxUniquesCodeH(database, logger));
//		addTest(new CreateIdxUniquesKeyBt(database, logger));
		addTest(new CreateIdxUpdatesCodeH(database, logger));
//		addTest(new CreateIdxUpdatesDecimBt(database, logger));
//		addTest(new CreateIdxUpdatesDoubleBt(database, logger));
//		addTest(new CreateIdxUpdatesIntBt(database, logger));
//		addTest(new CreateIdxUpdatesKeyBt(database, logger));
		addTest(new Join2(database, logger));
		addTest(new Join2Cl(database, logger));
		addTest(new Join3Cl(database, logger));
		addTest(new Join3Ncl(database, logger));
		addTest(new Join4Cl(database, logger));
		addTest(new Join4Ncl(database, logger));
//		addTest(new MuCheckmod100Rand(database, logger));
//		addTest(new MuCheckmod100Seq(database, logger));
//		addTest(new MuMod100Rand(database, logger));
//		addTest(new MuOltpUpdate(database, logger));
//		addTest(new MuUnmod100Rand(database, logger));
//		addTest(new MuUnmod100Seq(database, logger));
		addTest(new Proj100(database, logger));
		addTest(new Proj10Pct(database, logger));
		addTest(new Sel100Cl(database, logger));
		addTest(new Sel100Ncl(database, logger));
		addTest(new Sel10PctNcl(database, logger));
		addTest(new Sel1Cl(database, logger));
		addTest(new SelVariableSelectHigh(database, logger));
		addTest(new SelVariableSelectLow(database, logger));
		addTest(new TableScan(database, logger));
		addTest(new UpdAppendDuplicate(database, logger));
		addTest(new UpdAppTEnd(database, logger));
		addTest(new UpdAppTMid(database, logger));
		addTest(new UpdDelTEnd(database, logger));
		addTest(new UpdDelTMid(database, logger));
		addTest(new UpdIntegrityTest(database, logger));
		addTest(new UpdModTCod(database, logger));
		addTest(new UpdModTEnd(database, logger));
		addTest(new UpdModTInt(database, logger));
		addTest(new UpdModTMid(database, logger));
		addTest(new UpdRemoveDuplicate(database, logger));
	}
	virtual ~AS3APSuite() {}
};

#endif
