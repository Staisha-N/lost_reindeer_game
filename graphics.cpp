#include "graphics.hpp"

char * createBoard ();

char * createBoard() {
    /*
    Bit mask legend:
        Ocean (~) = 0
        Yukon = 1
        Northwest Territories = 2
        Nunavut = 3
        British Columbia = 4
        Alberta = 5
        Saskatchewan = 6
        Manitoba = 7
        Ontario = 8
        Quebec = 9
        New Brunswick = 10
        Nova Scotia = 11
        Prince Edward Island = 12
        Newfoundland and Labrador = 13
        Marked as no reindeer = 14
    */
    
    
    canada_graphic can;
    char *board{new char[1071]{}};
    
    //Ocean
    for (std::size_t i{}; i < 1071; i++) {
        if (can.characters[i] == '~') {
            board[i] = 0;
        }
    }

    //Yukon
        board[209] = 1;
        board[259] = 1;
        board[260] = 1;
        board[261] = 1;
        board[308] = 1;
        board[309] = 1;
        board[310] = 1;
        board[311] = 1;
        board[312] = 1;
        board[357] = 1;
        board[358] = 1;
        board[359] = 1;
        board[360] = 1;
        board[361] = 1;
        board[362] = 1;
        board[363] = 1;
        board[408] = 1;
        board[409] = 1;
        board[410] = 1;
        board[411] = 1;
        board[412] = 1;
        board[413] = 1;
        board[414] = 1;
        board[464] = 1;
        board[465] = 1;

    //Northwest Territories
        board[119] = 2;

        board[168] = 2;
        board[169] = 2;

        board[216] = 2;
        board[217] = 2;
        board[218] = 2;
        board[219] = 2;

        board[262] = 2;
        board[263] = 2;
        board[264] = 2;
        board[265] = 2;
        board[269] = 2;
        board[270] = 2;
        board[271] = 2;

        board[313] = 2;
        board[314] = 2;
        board[315] = 2;
        board[316] = 2;
        board[317] = 2;
        board[318] = 2;
        
        board[364] = 2;
        board[365] = 2;
        board[366] = 2;
        board[367] = 2;
        board[368] = 2;
        board[369] = 2;
        
        board[415] = 2;
        board[416] = 2;
        board[417] = 2;
        board[418] = 2;
        board[419] = 2;
        board[420] = 2;
        board[421] = 2;
        board[422] = 2;
        
        
        board[466] = 2;
        board[467] = 2;
        board[468] = 2;
        board[469] = 2;
        board[470] = 2;
        board[471] = 2;
        board[472] = 2;
        board[473] = 2;
        board[474] = 2;
        board[475] = 2;
        board[476] = 2;
        board[477] = 2;

        board[519] = 2;
        board[520] = 2;
        board[521] = 2;
        board[522] = 2;
        board[523] = 2;
        board[524] = 2;
        board[525] = 2;
        board[526] = 2;
        board[527] = 2;
        board[528] = 2;
        
        board[576] = 2;
        board[577] = 2;
        board[578] = 2;
        board[579] = 2;
        
        
    //Nunavut
        board[23] = 3;
        board[24] = 3;
        board[25] = 3;

        board[72] = 3;
        board[73] = 3;
        board[74] = 3;
        board[75] = 3;
        board[76] = 3;

        board[121] = 3;
        board[122] = 3;
        board[124] = 3;
        board[125] = 3;
        board[126] = 3;
        board[127] = 3;

        board[171] = 3;
        board[172] = 3;
        board[173] = 3;
        board[174] = 3;
        board[175] = 3;
        board[176] = 3;
        board[177] = 3;
        board[178] = 3;

        board[225] = 3;
        board[226] = 3;
        board[227] = 3;
        board[228] = 3;
        board[229] = 3;

        board[272] = 3;
        board[273] = 3;
        board[275] = 3;
        board[276] = 3;
        board[277] = 3;
        board[279] = 3;
        board[280] = 3;
        board[281] = 3;
        board[282] = 3;
        board[283] = 3;
        board[284] = 3;

        board[319] = 3;
        board[320] = 3; 
        board[321] = 3;
        board[322] = 3;
        board[323] = 3;
        board[324] = 3;
        board[325] = 3;
        board[327] = 3;
        board[328] = 3;
        board[330] = 3;
        board[331] = 3;
        board[332] = 3;
        board[333] = 3;
        board[334] = 3;
        board[335] = 3;
        board[336] = 3;
        board[337] = 3;
        board[338] = 3;

        board[370] = 3;
        board[371] = 3;
        board[372] = 3;
        board[373] = 3;
        board[374] = 3;
        board[375] = 3;
        board[378] = 3;
        board[379] = 3;
        board[380] = 3;
        board[381] = 3;
        board[383] = 3;
        board[386] = 3;
        board[388] = 3;
        board[389] = 3;
        board[390] = 3;
        board[391] = 3;
        board[392] = 3;

        board[423] = 3;
        board[424] = 3;
        board[425] = 3;
        board[426] = 3;
        board[427] = 3;
        board[428] = 3;
        board[429] = 3;
        board[430] = 3;
        board[431] = 3;
        board[432] = 3;
        board[433] = 3;
        board[434] = 3;

        board[438] = 3;
        board[439] = 3;  
        board[440] = 3;
        board[441] = 3;
        board[442] = 3;
        board[443] = 3;

        board[478] = 3;
        board[479] = 3;
        board[480] = 3;
        board[481] = 3;
        board[482] = 3;
        board[483] = 3;
        board[484] = 3;
        board[485] = 3;
        board[486] = 3;
        board[487] = 3;
        
        board[493] = 3;
        board[494] = 3;

        board[529] = 3;
        board[530] = 3;
        board[531] = 3;
        board[532] = 3;
        board[533] = 3;

        board[580] = 3;
        board[581] = 3;
        board[582] = 3;
        board[583] = 3;
        

    //British Columbia
        board[461] = 4;
        board[462] = 4;
        board[463] = 4;
        
        board[512] = 4;
        board[513] = 4;
        board[514] = 4;
        board[515] = 4;
        board[516] = 4;
        board[517] = 4;
        board[518] = 4;
        
        board[562] = 4;
        board[563] = 4;
        board[564] = 4;
        board[565] = 4;
        board[566] = 4;
        board[567] = 4;
        board[568] = 4;
        
        board[613] = 4;
        board[614] = 4;
        board[615] = 4;
        board[616] = 4;
        board[617] = 4;
        board[618] = 4;
        
        board[664] = 4;
        board[665] = 4;
        board[666] = 4;
        board[667] = 4;
        board[668] = 4;
        board[669] = 4;

        board[714] = 4;
        board[715] = 4;
        board[716] = 4;
        board[717] = 4;
        board[718] = 4;
        board[719] = 4;
        board[720] = 4;
        
        board[769] = 4;
        board[770] = 4;
        board[771] = 4;
        board[772] = 4;
        board[773] = 4;
        
        
    //Alberta
        board[569] = 5;
        board[570] = 5;
        board[571] = 5;
        board[572] = 5;
        board[573] = 5;
        board[574] = 5;
        board[575] = 5;
        
        board[619] = 5;
        board[620] = 5;
        board[621] = 5;
        board[622] = 5;
        board[623] = 5;
        board[624] = 5;
        board[625] = 5;
        
        board[670] = 5;
        board[671] = 5;
        board[672] = 5;
        board[673] = 5;
        board[674] = 5;
        board[675] = 5;
        
        board[721] = 5;
        board[722] = 5;
        board[723] = 5;
        board[724] = 5;
        board[725] = 5;
        
        board[773] = 5;
        board[774] = 5;
        board[775] = 5;
        
        board[825] = 5;

    //Saskatchewan
        board[626] = 6;
        board[627] = 6;
        board[628] = 6;
        board[629] = 6;
        
        board[676] = 6;
        board[677] = 6;
        board[678] = 6;
        board[679] = 6;
        board[680] = 6;
        
        board[726] = 6;
        board[727] = 6;
        board[728] = 6;
        board[729] = 6;
        board[730] = 6;
        
        board[776] = 6;
        board[777] = 6;
        board[778] = 6;
        board[779] = 6;
        board[780] = 6;
        board[781] = 6;
        
        board[826] = 6;
        board[827] = 6;
        board[828] = 6;
        board[829] = 6;
        board[830] = 6;
        board[831] = 6;
        

    //Manitoba
        board[630] = 7;
        board[631] = 7;
        board[632] = 7;
        board[633] = 7;
        board[634] = 7;
        
        board[681] = 7;
        board[682] = 7;
        board[683] = 7;
        board[684] = 7;
        board[685] = 7;
        board[686] = 7;
        board[687] = 7;

        board[731] = 7;
        board[732] = 7;
        board[733] = 7;
        board[734] = 7;
        board[735] = 7;
        board[736] = 7;
        
        board[782] = 7;
        board[783] = 7;
        board[784] = 7;
        board[785] = 7;
        
        board[832] = 7;
        board[833] = 7;
        board[834] = 7;
        board[835] = 7;
        board[836] = 7;
        
    //Ontario
        board[688] = 8;
        board[689] = 8;

        board[737] = 8;
        board[738] = 8;
        board[739] = 8;
        board[740] = 8;
        board[741] = 8;
        board[742] = 8;
        board[743] = 8;

        board[786] = 8;
        board[787] = 8;
        board[788] = 8;
        board[789] = 8;
        board[790] = 8;
        board[791] = 8;
        board[792] = 8;
        board[793] = 8;
        board[794] = 8;
        board[795] = 8;
        
        board[837] = 8;
        board[838] = 8;
        board[839] = 8;
        board[840] = 8;
        board[841] = 8;
        board[842] = 8;
        board[843] = 8;
        board[844] = 8;
        board[845] = 8;
        board[846] = 8;
        board[847] = 8;
        board[848] = 8;
        
        board[895] = 8;
        board[896] = 8;
        board[897] = 8;
        board[898] = 8;
        board[899] = 8;

        board[950] = 8;
        board[951] = 8;
        board[952] = 8;
        board[953] = 8;
        
        board[1001] = 8;
        board[1002] = 8;

        board[1051] = 8;

    //Quebec
        board[541] = 9;
        board[542] = 9;
        board[543] = 9;
        board[544] = 9;

        board[547] = 9;
        board[548] = 9;

        board[592] = 9;
        board[593] = 9;
        board[594] = 9;
        board[595] = 9;
        board[596] = 9;
        board[597] = 9;
        board[598] = 9;
        board[599] = 9;
        board[600] = 9;

        board[644] = 9;
        board[645] = 9;
        board[646] = 9;
        board[647] = 9;
        board[648] = 9;
        board[649] = 9;
        board[650] = 9;
        board[651] = 9;
        
        board[694] = 9;
        board[695] = 9;
        board[696] = 9;
        board[697] = 9;
        board[698] = 9;
        board[699] = 9;
        board[700] = 9;
        board[701] = 9;
        board[702] = 9;
        
        board[746] = 9;
        board[747] = 9;
        board[748] = 9;
        board[749] = 9;
        board[750] = 9;
        board[751] = 9;
        board[752] = 9;
        board[753] = 9;
        board[754] = 9;
        board[755] = 9;

        board[757] = 9;
        board[758] = 9;

        board[797] = 9;
        board[798] = 9;
        board[799] = 9;
        board[800] = 9;
        board[801] = 9;
        board[802] = 9;
        board[803] = 9;
        board[804] = 9;
        board[805] = 9;
        board[806] = 9;
        board[807] = 9;

        board[849] = 9;
        board[850] = 9;
        board[851] = 9;
        board[852] = 9;
        board[853] = 9;
        board[854] = 9;
        board[855] = 9;
        board[856] = 9;
        
        board[900] = 9;
        board[901] = 9;
        board[902] = 9;
        board[903] = 9;
        board[904] = 9;
        board[905] = 9;
        

    //New Brunswick
        board[808] = 10;

        board[858] = 10;
        board[859] = 10;
        board[860] = 10;
        board[861] = 10;

        board[910] = 10;
        board[911] = 10;
        
        
    //Nova Scotia
        board[812] = 11;
        board[862] = 11;
        board[912] = 11;
        
    //Prince Edward Island
        board[810] = 12;
        board[811] = 12;

    //Newfoundland and Labrador
        board[601] = 13;
        board[602] = 13;
        board[603] = 13;
        board[604] = 13;
        
        board[652] = 13;
        board[653] = 13;
        board[654] = 13;
        board[655] = 13;
        board[656] = 13;
        board[657] = 13;
        board[658] = 13;

        board[660] = 13;
        board[661] = 13;
        board[662] = 13;
        
        board[703] = 13;
        board[704] = 13;
        board[705] = 13;
        board[706] = 13;
        board[707] = 13;
        
        board[704] = 13;
        board[705] = 13;
        board[706] = 13;
        board[707] = 13;
        
        board[710] = 13;
        board[711] = 13;
        board[712] = 13;
        board[713] = 13;
        
        
        
    return board;
}