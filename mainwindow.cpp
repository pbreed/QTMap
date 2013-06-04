/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/


#include "mainwindow.h"
#include "view.h"
#include "myscene.h"
#include "wp.h"

#include <QHBoxLayout>
#include <QSplitter>
#include <QtWidgets>

MainWindow::MainWindow()
{
    Holder = new QWidget(this);
    setCentralWidget(Holder);

    populateScene();
/*
    h1Splitter = new QSplitter;
    h2Splitter = new QSplitter;
    
    QSplitter *vSplitter = new QSplitter;
    vSplitter->setOrientation(Qt::Vertical);
    vSplitter->addWidget(h1Splitter);
    vSplitter->addWidget(h2Splitter);

    View *view = new View("Top left view");
    view->view()->setScene(scene);
    h1Splitter->addWidget(view);

    view = new View("Top right view");
    view->view()->setScene(scene);
    h1Splitter->addWidget(view);

    view = new View("Bottom left view");
    view->view()->setScene(scene);
    h2Splitter->addWidget(view);

    view = new View("Bottom right view");
    view->view()->setScene(scene);
    h2Splitter->addWidget(view);
*/
    View * view = new View("One view");
    view->view()->setScene(scene);
    //h2Splitter->addWidget(view);

     List = new  QListWidget(this);

    QSplitter *vSplitter = new QSplitter;
    vSplitter->setOrientation(Qt::Vertical);
    vSplitter->addWidget(view);
    vSplitter->addWidget(List);


    QHBoxLayout *layout = new QHBoxLayout;
    //layout->addWidget(vSplitter);
    layout->addWidget(vSplitter);

    Holder->setLayout(layout);

    setWindowTitle(tr("MAP"));

    createActions();
    createMenus();
    createToolBars();
    createStatusBar();

    readSettings();

    setCurrentFile("");
    setUnifiedTitleAndToolBarOnMac(true);

}


const int co[]={
        +0,                  +0,
        +5,                  +1,
        +8,                  +2,
       +15,                  +3,
       +20,                  +3,
       +23,                  -2,
       +28,                  -6,
       +31,                  -9,
       +26,                 -19,
        -4,                 -62,
       -65,                -155,
      -142,                -295,
      -223,                -488,
      -310,                -727,
      -418,               -1004,
      -579,               -1280,
      -751,               -1543,
      -923,               -1808,
     -1097,               -2086,
     -1248,               -2419,
     -1395,               -2804,
     -1540,               -3217,
     -1661,               -3648,
     -1772,               -4100,
     -1885,               -4575,
     -1999,               -5076,
     -2121,               -5595,
     -2238,               -6124,
     -2303,               -6657,
     -2279,               -7183,
     -2151,               -7687,
     -1914,               -8147,
     -1585,               -8567,
     -1208,               -8972,
      -790,               -9358,
      -322,               -9706,
      +192,               -9994,
      +743,              -10195,
     +1317,              -10303,
     +1894,              -10326,
     +2445,              -10267,
     +2957,              -10137,
     +3431,               -9959,
     +3886,               -9753,
     +4343,               -9531,
     +4804,               -9292,
     +5288,               -9035,
     +5799,               -8758,
     +6329,               -8466,
     +6872,               -8162,
     +7423,               -7851,
     +7967,               -7530,
     +8475,               -7177,
     +8941,               -6784,
     +9385,               -6372,
     +9791,               -5943,
    +10109,               -5476,
    +10288,               -4979,
    +10279,               -4495,
    +10081,               -4058,
     +9731,               -3699,
     +9264,               -3436,
     +8715,               -3261,
     +8121,               -3185,
     +7502,               -3204,
     +6868,               -3298,
     +6249,               -3446,
     +5626,               -3651,
     +5018,               -3879,
     +4426,               -4116,
     +3831,               -4356,
     +3233,               -4598,
     +2622,               -4846,
     +1998,               -5097,
     +1365,               -5357,
      +709,               -5619,
       +40,               -5848,
      -577,               -5979,
     -1092,               -6019,
     -1580,               -6049,
     -2102,               -6115,
     -2664,               -6239,
     -3253,               -6369,
     -3876,               -6480,
     -4488,               -6571,
     -5111,               -6658,
     -5752,               -6752,
     -6394,               -6884,
     -6989,               -7117,
     -7477,               -7474,
     -7780,               -7942,
     -7892,               -8467,
     -7879,               -9011,
     -7786,               -9549,
     -7596,              -10063,
     -7319,              -10532,
     -7001,              -10967,
     -6668,              -11373,
     -6321,              -11755,
     -5937,              -12106,
     -5505,              -12409,
     -5059,              -12668,
     -4614,              -12905,
     -4177,              -13123,
     -3735,              -13317,
     -3297,              -13487,
     -2868,              -13649,
     -2431,              -13789,
     -1952,              -13849,
     -1421,              -13784,
      -855,              -13576,
      -298,              -13248,
      +223,              -12860,
      +713,              -12458,
     +1180,              -12066,
     +1625,              -11705,
     +2030,              -11389,
     +2395,              -11110,
     +2770,              -10826,
     +3213,              -10516,
     +3719,              -10203,
     +4281,               -9931,
     +4866,               -9686,
     +5442,               -9433,
     +5995,               -9156,
     +6513,               -8863,
     +6989,               -8550,
     +7431,               -8210,
     +7796,               -7805,
     +8068,               -7346,
     +8249,               -6868,
     +8346,               -6391,
     +8387,               -5923,
     +8387,               -5465,
     +8312,               -5017,
     +8146,               -4612,
     +7862,               -4241,
     +7502,               -3920,
     +7088,               -3651,
     +6638,               -3426,
     +6175,               -3230,
     +5709,               -3062,
     +5232,               -2932,
     +4736,               -2835,
     +4221,               -2789,
     +3678,               -2763,
     +3126,               -2744,
     +2566,               -2708,
     +2014,               -2645,
     +1479,               -2569,
      +953,               -2501,
      +433,               -2446,
       -67,               -2390,
      -555,               -2328,
     -1033,               -2265,
     -1507,               -2209,
     -1978,               -2176,
     -2442,               -2185,
     -2883,               -2249,
     -3295,               -2362,
     -3669,               -2518,
     -3990,               -2716,
     -4255,               -2929,
     -4490,               -3148,
     -4714,               -3377,
     -4937,               -3614,
     -5162,               -3860,
     -5401,               -4116,
     -5635,               -4377,
     -5861,               -4648,
     -6057,               -4933,
     -6222,               -5240,
     -6357,               -5553,
     -6461,               -5879,
     -6519,               -6217,
     -6495,               -6561,
     -6384,               -6897,
     -6178,               -7186,
     -5911,               -7422,
     -5590,               -7600,
     -5250,               -7752,
     -4891,               -7884,
     -4513,               -7998,
     -4113,               -8094,
     -3703,               -8186,
     -3290,               -8281,
     -2833,               -8343,
     -2361,               -8408,
     -1865,               -8476,
     -1354,               -8561,
      -847,               -8645,
      -360,               -8724,
      +111,               -8792,
      +574,               -8854,
     +1044,               -8915,
     +1519,               -8964,
     +2007,               -9005,
     +2512,               -9045,
     +3040,               -9088,
     +3595,               -9119,
     +4170,               -9123,
     +4751,               -9083,
     +5308,               -8969,
     +5800,               -8786,
     +6206,               -8551,
     +6537,               -8281,
     +6797,               -8002,
     +6986,               -7726,
     +7123,               -7469,
     +7217,               -7229,
     +7297,               -6984,
     +7342,               -6725,
     +7360,               -6450,
     +7372,               -6165,
     +7376,               -5875,
     +7367,               -5577,
     +7381,               -5293,
     +7365,               -5004,
     +7279,               -4699,
     +7128,               -4390,
     +6921,               -4083,
     +6665,               -3778,
     +6373,               -3487,
     +6018,               -3212,
     +5604,               -2964,
     +5109,               -2764,
     +4575,               -2603,
     +4031,               -2461,
     +3484,               -2332,
     +2937,               -2212,
     +2382,               -2089,
     +1818,               -1965,
     +1249,               -1858,
      +672,               -1795,
      +106,               -1792,
      -441,               -1874,
      -938,               -2048,
     -1353,               -2299,
     -1686,               -2573,
     -1978,               -2843,
     -2265,               -3107,
     -2552,               -3371,
     -2839,               -3633,
     -3134,               -3895,
     -3427,               -4159,
     -3722,               -4434,
     -4016,               -4720,
     -4315,               -5018,
     -4618,               -5322,
     -4932,               -5641,
     -5247,               -5968,
     -5553,               -6290,
     -5842,               -6599,
     -6127,               -6904,
     -6415,               -7197,
     -6701,               -7473,
     -7002,               -7739,
     -7336,               -7988,
     -7697,               -8227,
     -8073,               -8458,
     -8466,               -8692,
     -8866,               -8935,
     -9240,               -9203,
     -9555,               -9483,
     -9810,               -9748,
    -10029,               -9998,
    -10238,              -10259,
    -10458,              -10533,
    -10661,              -10820,
    -10827,              -11131,
    -10993,              -11450,
    -11228,              -11758,
    -11590,              -12028,
    -12056,              -12230,
    -12574,              -12353,
    -13117,              -12439,
    -13656,              -12523,
    -14188,              -12609,
    -14746,              -12671,
    -15327,              -12621,
    -15890,              -12432,
    -16390,              -12148,
    -16838,              -11825,
    -17245,              -11475,
    -17575,              -11074,
    -17801,              -10629,
    -17886,              -10155,
    -17788,               -9688,
    -17501,               -9302,
    -17071,               -9042,
    -16560,               -8898,
    -16034,               -8819,
    -15515,               -8756,
    -15001,               -8681,
    -14486,               -8599,
    -13975,               -8517,
    -13469,               -8436,
    -12954,               -8345,
    -12430,               -8245,
    -11906,               -8098,
    -11395,               -7861,
    -10924,               -7568,
    -10488,               -7274,
    -10067,               -6997,
     -9649,               -6733,
     -9231,               -6474,
     -8811,               -6218,
     -8385,               -5975,
     -7951,               -5738,
     -7513,               -5505,
     -7072,               -5276,
     -6630,               -5049,
     -6183,               -4829,
     -5729,               -4614,
     -5268,               -4406,
     -4802,               -4198,
     -4324,               -3999,
     -3824,               -3797,
     -3327,               -3615,
     -2820,               -3424,
     -2309,               -3226,
     -1789,               -3039,
     -1245,               -2890,
      -676,               -2791,
       -96,               -2723,
      +487,               -2704,
     +1080,               -2818,
     +1613,               -3111,
     +1984,               -3523,
     +2192,               -4367,
     +2203,               -4730,
     +2230,               -5049,
     +2267,               -5357,
     +2304,               -5685,
     +2339,               -6024,
     +2380,               -6368,
     +2439,               -6713,
     +2515,               -7065,
     +2611,               -7423,
     +2710,               -7794,
     +2828,               -8167,
     +2957,               -8552,
     +3108,               -8936,
     +3274,               -9315,
     +3448,               -9665,
     +3609,               -9978,
     +3721,              -10288,
     +3779,              -10602,
     +3764,              -10913,
     +3686,              -11200,
     +3555,              -11464,
     +3380,              -11700,
     +3177,              -11912,
     +2953,              -12109,
     +2715,              -12304,
     +2469,              -12512,
     +2208,              -12728,
     +1932,              -12958,
     +1639,              -13184,
     +1329,              -13404,
     +1013,              -13621,
      +682,              -13847,
      +338,              -14070,
       -20,              -14283,
      -387,              -14493,
      -750,              -14686,
     -1105,              -14875,
     -1452,              -15070,
     -1793,              -15270,
     -2143,              -15465,
     -2512,              -15653,
     -2902,              -15836,
     -3305,              -16020,
     -4142,              -16319,
     -4571,              -16408,
     -4982,              -16450,
     -5362,              -16448,
     -5719,              -16395,
     -6059,              -16303,
     -6376,              -16157,
     -6673,              -15941,
     -6940,              -15674,
     -7152,              -15375,
     -7324,              -15063,
     -7476,              -14751,
     -7616,              -14456,
     -7749,              -14180,
     -7886,              -13927,
     -8021,              -13702,
     -8173,              -13467,
     -8301,              -13282,
     -8413,              -13176,
     -8535,              -13064,
     -8676,              -12882,
     -8847,              -12602,
     -9018,              -12272,
     -9187,              -11934,
     -9363,              -11602,
     -9586,              -11222,
     -9843,              -10784,
    -10099,              -10351,
    -10346,               -9918,
    -10535,               -9438,
    -10575,               -8904,
    -10430,               -8367,
    -10133,               -7871,
     -9774,               -7408,
     -9426,               -6952,
     -9096,               -6499,
     -8752,               -6058,
     -8334,               -5658,
     -7834,               -5355,
     -6783,               -5010,
     -6269,               -4858,
     -5756,               -4691,
     -5257,               -4534,
     -4751,               -4367,
     -4223,               -4180,
     -3701,               -3980,
     -3200,               -3772,
     -2717,               -3568,
     -2248,               -3369,
     -1787,               -3168,
     -1325,               -2979,
      -896,               -2739,
      -455,               -2508,
        +8,               -2308,
      +485,               -2137,
      +974,               -1992,
     +1451,               -1832,
     +1938,               -1694,
     +2422,               -1559,
     +2931,               -1473,
     +3466,               -1454,
     +4026,               -1571,
     +4562,               -1830,
     +5048,               -2184,
     +5435,               -2617,
     +5680,               -3120,
     +5804,               -3618,
     +5858,               -4033,
     +5893,               -4357,
     +5937,               -4647,
     +5983,               -4946,
     +6028,               -5267,
     +6069,               -5606,
     +6124,               -5952,
     +6197,               -6298,
     +6294,               -6640,
     +6420,               -6965,
     +6569,               -7280,
     +6731,               -7593,
     +6901,               -7908,
     +7078,               -8232,
     +7258,               -8564,
     +7405,               -8890,
     +7476,               -9519,
     +7438,               -9832,
     +7394,              -10157,
     +7326,              -10486,
     +7203,              -10800,
     +7006,              -11082,
     +6744,              -11331,
     +6446,              -11564,
     +6114,              -11794,
     +5719,              -11976,
     +5273,              -12070,
     +4827,              -12060,
     +4423,              -11963,
     +4065,              -11784,
     +3716,              -11557,
     +3372,              -11303,
     +3031,              -11023,
     +2674,              -10722,
     +2299,              -10409,
     +1913,              -10089,
     +1530,               -9762,
     +1159,               -9436,
      +813,               -9095,
      +560,               -8681,
      +485,               -8187,
      +560,               -7670,
      +692,               -7156,
      +830,               -6655,
      +952,               -6171,
     +1095,               -5681,
     +1324,               -5195,
     +1634,               -4732,
     +1979,               -4303,
     +2334,               -3917,
     +2697,               -3556,
     +3061,               -3198,
     +3425,               -2850,
     +3810,               -2525,
     +4214,               -2229,
     +4633,               -1977,
     +5068,               -1764,
     +5508,               -1574,
     +5946,               -1390,
     +6377,               -1213,
     +7192,                -818,
     +7580,                -602,
     +7956,                -371,
     +8306,                -116,
     +8606,                +177,
     +8812,                +522,
     +8899,                +886,
     +8877,               +1226,
     +8776,               +1527,
     +8615,               +1804,
     +8407,               +2065,
     +8174,               +2306,
     +7895,               +2524,
     +7594,               +2731,
     +7262,               +2940,
     +6900,               +3103,
     +6506,               +3228,
     +6072,               +3295,
     +5615,               +3297,
     +5143,               +3239,
     +4673,               +3112,
     +4214,               +2941,
     +3745,               +2749,
     +3291,               +2534,
     +2864,               +2311,
     +2452,               +2062,
     +2069,               +1795,
     +1715,               +1504,
     +1408,               +1164,
     +1154,                +808,
      +944,                +439,
      +760,                 +56,
      +598,                -335,
      +449,                -740,
      +279,               -1106,
       +97,               -1422,
       -66,               -1729,
      -214,               -2029,
      -356,               -2308,
      -506,               -2581,
      -679,               -2852,
      -882,               -3109,
     -1096,               -3345,
     -1325,               -3571,
     -1552,               -3790,
     -1756,               -4019,
     -1938,               -4251,
     -2100,               -4485,
     -2236,               -4727,
     -2332,               -4982,
     -2383,               -5234,
     -2375,               -5489,
     -2318,               -5744,
     -2212,               -5999,
     -2078,               -6260,
     -1910,               -6522,
     -1712,               -6768,
     -1492,               -7001,
     -1232,               -7192,
      -951,               -7364,
      -656,               -7529,
      -352,               -7674,
       -36,               -7803,
      +294,               -7929,
      +639,               -8054,
      +996,               -8186,
     +1370,               -8325,
     +1762,               -8463,
     +2160,               -8579,
     +2575,               -8686,
     +3000,               -8768,
     +3434,               -8810,
     +3869,               -8817,
     +4298,               -8776,
     +4723,               -8682,
     +5148,               -8555,
     +5570,               -8406,
     +5989,               -8227,
     +6406,               -8023,
     +7129,               -7512,
     +7408,               -7218,
     +7632,               -6905,
     +7838,               -6591,
     +8045,               -6271,
     +8250,               -5942,
     +8431,               -5598,
     +8573,               -5241,
     +8655,               -4865,
     +8677,               -4466,
     +8673,               -4068,
     +8647,               -3666,
     +8625,               -3268,
     +8582,               -2856,
     +8526,               -2443,
     +8437,               -2018,
     +8316,               -1579,
     +8167,               -1143,
     +7997,                -729,
     +7812,                -353,
     +7618,                  -1,
     +7414,                +336,
     +7200,                +642,
     +6989,                +927,
     +6769,               +1187,
     +6545,               +1435,
     +6325,               +1664,
     +6092,               +1875,
     +5819,               +2062,
     +5512,               +2204,
     +5170,               +2269,
     +4802,               +2251,
     +4421,               +2141,
     +4040,               +1959,
     +3686,               +1729,
     +3364,               +1465,
     +3043,               +1189,
     +2706,                +900,
     +2353,                +611,
     +2007,                +344,
     +1680,                +101,
     +1369,                -126,
     +1069,                -342,
      +778,                -549,
      +489,                -748,
      +199,                -941,
       -90,               -1128,
      -383,               -1305,
      -673,               -1466,
      -948,               -1609,
     -1200,               -1750,
     -1439,               -1903,
     -1668,               -2071,
     -1897,               -2255,
     -2133,               -2459,
     -2378,               -2676,
     -2639,               -2913,
     -2914,               -3176,
     -3202,               -3474,
     -3502,               -3801,
     -3805,               -4156,
     -4098,               -4534,
     -4351,               -4921,
     -4553,               -5310,
     -4746,               -5718,
     -4955,               -6152,
     -5173,               -6605,
     -5403,               -7075,
     -5659,               -7554,
     -5927,               -8010,
     -6171,               -8416,
     -6389,               -8791,
     -6602,               -9179,
     -6837,               -9593,
     -7112,              -10020,
     -7401,              -10465,
     -7590,              -10963,
     -7555,              -11474,
     -7295,              -11930,
     -6911,              -12295,
     -6473,              -12576,
     -6008,              -12774,
     -5548,              -12878,
     -5114,              -12918,
     -4703,              -12909,
     -4320,              -12862,
     -3967,              -12781,
     -3637,              -12675,
     -3331,              -12555,
     -3049,              -12418,
     -2787,              -12251,
     -2549,              -12060,
     -2342,              -11852,
     -2159,              -11629,
     -2004,              -11390,
     -1872,              -11144,
     -1768,              -10889,
     -1686,              -10620,
     -1623,              -10346,
     -1559,              -10056,
     -1495,               -9775,
     -1408,               -9516,
     -1330,               -9295,
     -1211,               -9039,
     -1091,               -8779,
      -909,               -8466,
      -695,               -8126,
      -458,               -7801,
      -210,               -7509,
       +45,               -7249,
      +305,               -7011,
      +572,               -6779,
      +861,               -6534,
     +1181,               -6283,
     +1521,               -6031,
     +1864,               -5785,
     +2212,               -5566,
     +2563,               -5363,
     +2922,               -5187,
     +3290,               -5037,
     +3666,               -4905,
     +4055,               -4812,
     +4452,               -4764,
     +4835,               -4729,
     +5201,               -4706,
     +5552,               -4680,
     +5886,               -4660,
     +6200,               -4641,
     +6498,               -4625,
     +6777,               -4579,
     +7021,               -4473,
     +7200,               -4263,
     +7317,               -3967,
     +7413,               -3676,
     +7488,               -3384,
     +7524,               -3080,
     +7549,               -2776,
     +7580,               -2505,
     +7589,               -2224,
     +7561,               -1921,
     +7496,               -1618,
     +7407,               -1323,
     +7290,               -1003,
     +7139,                -690,
     +6943,                -409,
     +6717,                -149,
     +6459,                 +89,
     +6165,                +265,
     +5846,                +391,
     +5495,                +444,
     +5125,                +471,
     +4768,                +443,
     +4434,                +345,
     +4119,                +215,
     +3840,                 +64,
     +3569,                 -86,
     +3298,                -235,
     +3035,                -379,
     +2780,                -518,
     +2527,                -657,
     +2275,                -790,
     +2027,                -910,
     +1777,               -1017,
     +1520,               -1118,
     +1270,               -1217,
     +1029,               -1327,
      +804,               -1447,
      +591,               -1565,
      +416,               -1685,
      +307,               -1757,
      +250,               -1786,
      +220,               -1790,
      +204,               -1788,
      +190,               -1784,
      +173,               -1777,
      +158,               -1769,
      +146,               -1763,
      +131,               -1759,
      +116,               -1753,
      +110,               -1738,
      +102,               -1726,
       +94,               -1713,
       +85,               -1702,
       +80,               -1692,
       +82,               -1680,
       +77,               -1675,
       +71,               -1664,
       +68,               -1649,
       +64,               -1634,
       +59,               -1622,
       +53,               -1610,
       +46,               -1603,
       +46,               -1593,
       +45,               -1581,
       +41,               -1571,
       +40,               -1556,
       +38,               -1542,
       +36,               -1533,
       -9999,-9999};


void MainWindow::populateScene()
{
    scene = new MyScene(this);


    int nitems = 0;
    // Populate scene
    for(int i=-10000; i<10000; i+=100)
    {
        QGraphicsItem * item= new QGraphicsLineItem(-10000,i,10000,i);
        scene->addItem(item);
        ++nitems;
        item= new QGraphicsLineItem(i,-10000,i,10000);
        scene->addItem(item);
        ++nitems;
     }

        QPen * pQp=new QPen(QColor(0,255,0));

        pQp->setWidth(25);


    int index=1;
    while((co[index]!=-9999) && (co[index+1]!=-9999))
    {
        int x1=co[index-2];
        int y1=co[index-1];
        int x2=co[index];
        int y2=co[index+1];
        index+=2;
        QGraphicsLineItem * item= new QGraphicsLineItem(x1,y1,x2,y2);
        item->setPen(*pQp);
        scene->addItem(item);
        ++nitems;
        if(index>600)break;
    }



  /*  int xx = 0;
    int nitems = 0;
    for (int i = -11000; i < 11000; i += 110) {
        ++xx;
        int yy = 0;
        for (int j = -7000; j < 7000; j += 70) {
            ++yy;
            qreal x = (i + 11000) / 22000.0;
            qreal y = (j + 7000) / 14000.0;

            QColor color(image.pixel(int(image.width() * x), int(image.height() * y)));
            QGraphicsItem *item = new Chip(color, xx, yy);
            item->setPos(QPointF(i, j));
            scene->addItem(item);

            ++nitems;
        }
    }
    */
}

void MainWindow::closeEvent(QCloseEvent *event)
//! [3] //! [4]
{
    if (maybeSave()) {
        writeSettings();
        event->accept();
    } else {
        event->ignore();
    }
}
//! [4]

//! [5]
void MainWindow::newFile()
//! [5] //! [6]
{
    if (maybeSave()) {
        setCurrentFile("");
    }
}
//! [6]

//! [7]
void MainWindow::open()
//! [7] //! [8]
{
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty()) loadFile(fileName);
    }
}
//! [8]

//! [9]
bool MainWindow::save()
//! [9] //! [10]
{
    if (curFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}
//! [10]

//! [11]
bool MainWindow::saveAs()
//! [11] //! [12]
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}
//! [12]

//! [13]
void MainWindow::about()
//! [13] //! [14]
{
   QMessageBox::about(this, tr("About Application"),
            tr("The <b>Application</b> example demonstrates how to "
               "write modern GUI applications using Qt, with a menu bar, "
               "toolbars, and a status bar."));
}
//! [14]

//! [15]
void MainWindow::documentWasModified()
//! [15] //! [16]
{
    //setWindowModified(textEdit->document()->isModified());
}
//! [16]

//! [17]
void MainWindow::createActions()
//! [17] //! [18]
{
    newAct = new QAction(QIcon(":/images/new.png"), tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

//! [19]
    openAct = new QAction(QIcon(":/images/open.png"), tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
//! [18] //! [19]

    saveAct = new QAction(QIcon(":/images/save.png"), tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAct = new QAction(tr("Save &As..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Save the document under a new name"));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

//! [20]
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
//! [20]
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

//! [21]
    cutAct = new QAction(QIcon(":/images/cut.png"), tr("Cu&t"), this);
//! [21]
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the clipboard"));
    //connect(cutAct, SIGNAL(triggered()), textEdit, SLOT(cut()));

    copyAct = new QAction(QIcon(":/images/copy.png"), tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the clipboard"));
    //connect(copyAct, SIGNAL(triggered()), textEdit, SLOT(copy()));

    pasteAct = new QAction(QIcon(":/images/paste.png"), tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    //connect(pasteAct, SIGNAL(triggered()), textEdit, SLOT(paste()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

//! [22]
    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
//! [22]

//! [23]
    cutAct->setEnabled(false);
//! [23] //! [24]
    copyAct->setEnabled(false);
    //connect(textEdit, SIGNAL(copyAvailable(bool)),  cutAct, SLOT(setEnabled(bool)));
    //connect(textEdit, SIGNAL(copyAvailable(bool)), copyAct, SLOT(setEnabled(bool)));
}
//! [24]

//! [25] //! [26]
void MainWindow::createMenus()
//! [25] //! [27]
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
//! [28]
    fileMenu->addAction(openAct);
//! [28]
    fileMenu->addAction(saveAct);
//! [26]
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}
//! [27]

//! [29] //! [30]
void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
//! [29] //! [31]
    fileToolBar->addAction(openAct);
//! [31]
    fileToolBar->addAction(saveAct);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(cutAct);
    editToolBar->addAction(copyAct);
    editToolBar->addAction(pasteAct);
}
//! [30]

//! [32]
void MainWindow::createStatusBar()
//! [32] //! [33]
{
    statusBar()->showMessage(tr("Ready"));
}
//! [33]

//! [34] //! [35]
void MainWindow::readSettings()
//! [34] //! [36]
{
    QSettings settings("QtProject", "Application Example");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    resize(size);
    move(pos);
}
//! [35] //! [36]

//! [37] //! [38]
void MainWindow::writeSettings()
//! [37] //! [39]
{
    QSettings settings("QtProject", "Application Example");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}
//! [38] //! [39]

//! [40]
bool MainWindow::maybeSave()
//! [40] //! [41]
{
 /*   if (textEdit->document()->isModified()) {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("Application"),
                     tr("The document has been modified.\n"
                        "Do you want to save your changes?"),
                     QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
            return save();
        else if (ret == QMessageBox::Cancel)
            return false;
    }
   */
    return true;
}
//! [41]

//! [42]
void MainWindow::loadFile(const QString &fileName)
//! [42] //! [43]
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

     setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
}
//! [43]

//! [44]
bool MainWindow::saveFile(const QString &fileName)
//! [44] //! [45]
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}
//! [45]

//! [46]
void MainWindow::setCurrentFile(const QString &fileName)
//! [46] //! [47]
{
    curFile = fileName;
//    textEdit->document()->setModified(false);
    setWindowModified(false);

    QString shownName = curFile;
    if (curFile.isEmpty())
        shownName = "untitled.txt";
    setWindowFilePath(shownName);
}
//! [47]

//! [48]
QString MainWindow::strippedName(const QString &fullFileName)
//! [48] //! [49]
{
    return QFileInfo(fullFileName).fileName();
}
//! [49]



void MainWindow::AddWP(WP *p)
{
    WPList.append(p);
    QListWidgetItem * pi=new QListWidgetItem("");
     List->addItem(pi);
     p->SetRow(pi);

}


