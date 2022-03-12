#include <iostream>
#include <cassert>
#include "trivia.hpp"

void HelpHint(int province_num) {
    if (province_num == 1) {
        std::cout << "This is the westernmost territory." << std::endl;
    } else if (province_num == 2) {
        std::cout << "Due to the multitude of diamond mines located accross the territory, it is known as the Diamond Capital of North America." << std::endl;
    } else if (province_num == 3) {
        std::cout << "This province is the closest you can get in Canada to the North Pole." << std::endl;
    } else if (province_num == 4) {
        std::cout << "This province hosted the 2010 Winter Olympics." << std::endl;
    } else if (province_num == 5) {
        std::cout << "This province has the oldest national park in Canada (Banff)." << std::endl;
    } else if (province_num == 6) {
        std::cout << "The Royal Canadian Mounted Police (RCMP) academy is located in the capital of this province." << std::endl;
    } else if (province_num == 7) {
        std::cout << "A northern town in this province is known as the polar bear capital of the world." << std::endl;
    } else if (province_num == 8) {
        std::cout << "The world's largest skating rink is in the capital of this province." << std::endl;
    } else if (province_num == 9) {
        std::cout << "Poutine, the staple of Canadian cuisine, officially comes from this province." << std::endl;
    } else if (province_num == 10) {
        std::cout << "This is a maritime province that borders with Quebec." << std::endl;
    } else if (province_num == 11) {
        std::cout << "This is the second smallest province." << std::endl;
    } else if (province_num == 12) {
        std::cout << "The popular children's book \"Anne of Green Gables\" was written by an author from this province." << std::endl;
    } else {
        std::cout << "The world's first transatlantic flight took off from the capital of this province." << std::endl;
    }
    
}

void GetCarrots (int province_num, int &carrots) {

    //create a linked list for trivia questions?
    int num1 {0};
    char tf1 {};
    char tf2 {};

    if (province_num == 1) {
        std::cout << "How many provinces are in Canada? ";
        std::cin >> num1;
        if(num1 == 10) {
            carrots += 1;
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect. There are 10 provinces." << std::endl;
        }
        std::cout << "True or False: The Canadian-American border is the longest internation border in the world. Enter [t] or [f]: ";
        std::cin >> tf1;
        if((tf1 == 't') || (tf1 == 'T')) {
            carrots += 1;
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect." << std::endl;
        }
        std::cout << "True or False: Canada's national animal is the nine-banded armadillo. Enter [t] or [f]: ";
        std::cin >> tf2;
        if((tf2 == 'f') || (tf2 == 'F')) {
            carrots += 1;
            std::cout << "Correct! It's the beaver." << std::endl;
        } else {
            std::cout << "Incorrect. It's the beaver." << std::endl;
        }

    } else if (province_num == 2) {
        std::cout << "How many territories are in Canada? ";
        std::cin >> num1;
        if(num1 == 3) {
            carrots += 1;
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect. There are 3 territories." << std::endl;
        }
        std::cout << "True or False: Canada Day is celebrated on June 1st. Enter [t] or [f]: ";
        std::cin >> tf1;
        if((tf1 == 'f') || (tf1 == 'F')) {
            carrots += 1;
            std::cout << "Correct! It's July 1st." << std::endl;
        } else {
            std::cout << "Incorrect. It's July 1st." << std::endl;
        }
        std::cout << "True or False: The temperature in Canada has never reached below -70°C. Enter [t] or [f]: ";
        std::cin >> tf2;
        if ((tf2 == 't') || (tf2 == 'T')) {
            carrots += 1;
            std::cout << "Correct! It's cold here, but not that cold. The coldest ever recorded is -63°C." << std::endl;
        } else {
            std::cout << "Incorrect. It's cold here, but not that cold. The coldest ever recorded is -63°C." << std::endl;
        }
    } else if (province_num == 3) {
        std::cout << "How many maple leafs are on the Canadian flag? ";
        std::cin >> num1;
        if(num1 == 1) {
            carrots += 1;
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect. There is just one maple leaf." << std::endl;
        }
        std::cout << "True or False: In Canada, more children under the age of 14 play soccer than hockey. Enter [t] or [f]: ";
        std::cin >> tf1;
        if ((tf1 == 't') || (tf1 == 'T')) {
            carrots += 1;
            std::cout << "Correct! Almost twice as many kids under 14 years play soccer than hockey." << std::endl;
        } else {
            std::cout << "Incorrect. Surprisingly, almost twice as many kids under 14 years play soccer than hockey." << std::endl;
        }
        std::cout << "True or False: The famous singer Justin Beiber is Canadian. Enter [t] or [f]: ";
        std::cin >> tf2;
        if ((tf2 == 't') || (tf2 == 'T')) {
            carrots += 1;
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect. He's from Ontario, Canada." << std::endl;
        }
    } else if (province_num == 4) {
        std::cout << "How many oceans does Canada border with? ";
        std::cin >> num1;
        if(num1 == 3) {
            carrots += 1;
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect. There are 3 (Atlantic, Pacific and Arctic)." << std::endl;
        }
        std::cout << "True or False: There are less than 70 species of trees that grow in Canada. Enter [t] or [f]: ";
        std::cin >> tf1;
        if((tf1 == 'f') || (tf1 == 'F')) {
            carrots += 1;
            std::cout << "Correct! There are over 180 tree species in Canada." << std::endl;
        } else {
            std::cout << "Incorrect. There are over 180 tree species in Canada." << std::endl;
        }
        std::cout << "True or False: The capital of Canada (Ottawa) is its the most populated city. Enter [t] or [f]: ";
        std::cin >> tf2;
        if((tf2 == 'f') || (tf2 == 'F')) {
            carrots += 1;
            std::cout << "Correct! It's Toronto. Followed by Montreal. Then Vancouver, Calgary, and Edmonton." << std::endl;
        } else {
            std::cout << "Incorrect. It's Toronto. It's Toronto. Followed by Montreal. Then Vancouver, Calgary, and Edmonton." << std::endl;
        }
    } else if (province_num == 5) {
        std::cout << "How many provinces/territories does Hudson's Bay border with? ";
        std::cin >> num1;
        if(num1 == 4) {
            carrots += 1;
            std::cout << "Correct! The 4 it borders with are Nunavut, Manitoba, Ontario and Quebec." << std::endl;
        } else {
            std::cout << "Incorrect. The 4 it borders with are Nunavut, Manitoba, Ontario and Quebec." << std::endl;
        }
        std::cout << "True or False: Only 85\% of Canadians are literate, meaning they can read and write. Enter [t] or [f]: ";
        std::cin >> tf1;
        if((tf1 == 'f') || (tf1 == 'F')) {
            carrots += 1;
            std::cout << "Correct! Canadians are brighter than that. The Literacy Rate is 99%." << std::endl;
        } else {
            std::cout << "Incorrect. Canadians are brighter than that. The Literacy Rate is 99%." << std::endl;
        }
        std::cout << "True or False: The $1CAD coin was named \"loonie\" after the popular animated series \"Loonie Toons\". Enter [t] or [f]: ";
        std::cin >> tf2;
        if((tf2 == 'f') || (tf2 == 'F')) {
            carrots += 1;
            std::cout << "Correct! It was named after the loon, a species of aquatic bird." << std::endl;
        } else {
            std::cout << "Incorrect. It was named after the loon, a species of aquatic bird." << std::endl;
        }
    } else if (province_num == 6) {
        std::cout << "How many Great Lakes does Canada have? ";
        std::cin >> num1;
        if(num1 == 5) {
            carrots += 1;
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect. There are 5 (Superior, Huron, Michigan, Ontario and Erie)." << std::endl;
        }
        std::cout << "True or False: Saskatchewan is responsible for growing 70\% of Canada's grains such as wheat, canola, flax or rye.  Enter [t] or [f]: ";
        std::cin >> tf1;
        if((tf1 == 'f') || (tf1 == 'F')) {
            carrots += 1;
            std::cout << "Correct! It's only 45\%." << std::endl;
        } else {
            std::cout << "Incorrect. It's only 45\%." << std::endl;
        }
        std::cout << "True or False: The Northwest Territories of Canada recognizes 11 official languages.  Enter [t] or [f]: ";
        std::cin >> tf2;
        if ((tf2 == 't') || (tf2 == 'T')) {
            carrots += 1;
            std::cout << "Correct! Those languages are: Gwich'in, Chipewyan, Dené, Inuinnaqtun, Tłįchǫ Inuktitut, Cree, North Slavey, South Slavey, Inuvialuktun, English, and French." << std::endl;
        } else {
            std::cout << "Incorrect. The 11 recognized languages are: Gwich'in, Chipewyan, Dené, Inuinnaqtun, Tłįchǫ Inuktitut, Cree, North Slavey, South Slavey, Inuvialuktun, English, and French." << std::endl;
        }
    } else if (province_num == 7) {
        std::cout << "How many Maritime provinces does Canada have? ";
        std::cin >> num1;
        if(num1 == 3) {
            carrots += 1;
            std::cout << "Correct! The 3 Maritime provinces are New Brunswick, Nova Scotia, and Prince Edward Island." << std::endl;
        } else {
            std::cout << "Incorrect. The 3 Maritime provinces are New Brunswick, Nova Scotia, and Prince Edward Island." << std::endl;
        }
        std::cout << "True or False: Hockey is Canada's national sport. Enter [t] or [f]: ";
        std::cin >> tf1;
        if((tf1 == 'f') || (tf1 == 'F')) {
            carrots += 1;
            std::cout << "Correct! It's Lacrosse." << std::endl;
        } else {
            std::cout << "Incorrect. It's Lacrosse. I know. Ridiculous." << std::endl;
        }
        std::cout << "True or False: Canada officially became independent from Britain in 1882. Enter [t] or [f]: ";
        std::cin >> tf2;
        if((tf2 == 'f') || (tf2 == 'F')) {
            carrots += 1;
            std::cout << "Correct! Canada only officially became independent from Britain in 1982." << std::endl;
        } else {
            std::cout << "Incorrect. Canada only officially became independent from Britain in 1982." << std::endl;
        }
    } else if (province_num == 8) {
        std::cout << "How many time zones are spanned by Canada? ";
        std::cin >> num1;
        if(num1 == 6) {
            carrots += 1;
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect. Canada spans 6 timezones." << std::endl;
        }
        std::cout << "True or False: Winnie-the-Pooh was named after a bear from Canada. Enter [t] or [f]: ";
        std::cin >> tf1;
        if ((tf1 == 't') || (tf1 == 'T')) {
            carrots += 1;
            std::cout << "Correct! Winnie-the-Pooh was named after a black bear from Ontario at London Zoo called Winnie." << std::endl;
        } else {
            std::cout << "Incorrect. Winnie-the-Pooh was named after a black bear in Ontario, at London Zoo called Winnie." << std::endl;
        }
        std::cout << "True or False: The oak tree is Canada's national tree. Enter [t] or [f]: ";
        std::cin >> tf2;
        if((tf2 == 'f') || (tf2 == 'F')) {
            carrots += 1;
            std::cout << "Correct! It's the maple tree (duh!)" << std::endl;
        } else {
            std::cout << "Incorrect. It's the maple tree (duh!)" << std::endl;
        }
    } else if (province_num == 9) {
        std::cout << "How many 'fleurs de Lys' are on Quebec's flag? ";
        std::cin >> num1;
        if(num1 == 4) {
            carrots += 1;
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect. There are 4 (one in each corner)." << std::endl;
        }
        std::cout << "True or False: The first Canadian prime minister was Sir John Macdonald. Enter [t] or [f]: ";
        std::cin >> tf1;
        if ((tf1 == 't') || (tf1 == 'T')) {
            carrots += 1;
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect." << std::endl;
        }
        std::cout << "True or False: The Labrador retriever dog was named after the Canadian province of Newfoundland and Labrador. Enter [t] or [f]: ";
        std::cin >> tf2;
        if ((tf2 == 't') || (tf2 == 'T')) {
            carrots += 1;
            std::cout << "Correct! The breed originated in Newfoundland and Labrador in the 1500s." << std::endl;
        } else {
            std::cout << "Incorrect. The breed originated in Newfoundland and Labrador in the 1500s." << std::endl;
        }
    } else if (province_num == 10) {
        std::cout << "The number on Wayne Gretzky's hockey jersey is #___ ";
        std::cin >> num1;
        if(num1 == 99) {
            carrots += 1;
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect. He is #99." << std::endl;
        }
        std::cout << "True or False: The Niagara Falls are the second largest waterfalls in Canada by volume of water. Enter [t] or [f]: ";
        std::cin >> tf1;
        if((tf1 == 'f') || (tf1 == 'F')) {
            carrots += 1;
            std::cout << "Correct! The Niagara Falls are the largest." << std::endl;
        } else {
            std::cout << "Incorrect. The Niagara Falls are the largest." << std::endl;
        }
        std::cout << "True or False: The CN Tower is the tallest freestanding structure in the world. Enter [t] or [f]: ";
        std::cin >> tf2;
        if((tf2 == 'f') || (tf2 == 'F')) {
            carrots += 1;
            std::cout << "Correct! The tallest one is the Burj Khalifa in Dubai." << std::endl
            << "The CN tower is actually only the 10th tallest." << std::endl;
        } else {
            std::cout << "Inorrect. The tallest one is the Burj Khalifa in Dubai." << std::endl
            << "The CN tower is actually only the 10th tallest." << std::endl;
        }
    } else if (province_num == 11) {
        std::cout << "How many buffalos are on the RCMP badge? ";
        std::cin >> num1;
        if(num1 == 1) {
            carrots += 1;
            std::cout << "Correct! The RCMP Assistant Commissioner Macleod suggested a buffalo on the badge" << std::endl
            << "because he had been impressed with the great herds of prairie buffalo that he saw." << std::endl;
        } else {
            std::cout << "Incorrect. The RCMP Assistant Commissioner Macleod suggested a buffalo on the badge" << std::endl
            << "because he had been impressed with the great herds of prairie buffalo that he saw." << std::endl;
        }
        std::cout << "True or False: Canadians celebrate Thanksgiving in October. Enter [t] or [f]: ";
        std::cin >> tf1;
        if ((tf1 == 't') || (tf1 == 'T')) {
            carrots += 1;
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect. Canada celebrates Thanksgiving in the middle of October." << std::endl;
        }
        std::cout << "True or False: Ranked by area, Canada is the 3rd largest country in the world. Enter [t] or [f]: ";
        std::cin >> tf2;
        if((tf2 == 'f') || (tf2 == 'F')) {
            carrots += 1;
            std::cout << "Correct! Canada is the 2nd largest (after Russia)." << std::endl;
        } else {
            std::cout << "Inorrect. Canada is the 2nd largest (after Russia)." << std::endl;
        }
    } else if (province_num == 12) {
        std::cout << "How many official languages are recognized in Canada? ";
        std::cin >> num1;
        if(num1 == 2) {
            carrots += 1;
            std::cout << "Correct! English and French." << std::endl;
        } else {
            std::cout << "Incorrect. There are two: English and French." << std::endl;
        }
        std::cout << "True or False: The president of Canada works in the Canadian Red-and-White House. Enter [t] or [f]: ";
        std::cin >> tf1;
        if((tf1 == 'f') || (tf1 == 'F')) {
            carrots += 1;
            std::cout << "Correct! Canada has a prime minister, and there is no Red-and-White House." << std::endl;
        } else {
            std::cout << "Inorrect. Canada has a prime minister, and there is no Red-and-White House" << std::endl;
        }
        std::cout << "True or False: Tim Hortons is a Canadian high-end luxury fashion designer. Enter [t] or [f]: ";
        std::cin >> tf2;
        if((tf2 == 'f') || (tf2 == 'F')) {
            carrots += 1;
            std::cout << "Correct! Tim Hortons is a Canadian multinational fast food restaurant chain." << std::endl;
        } else {
            std::cout << "Inorrect. Tim Hortons is a Canadian multinational fast food restaurant chain." << std::endl;
        }
    } else {
        std::cout << "How many letters are in the name of the province with the longest name? ";
        std::cin >> num1;
        if(num1 == 23) {
            carrots += 1;
            std::cout << "Correct! \"Newfoundland and Labrador\" has 23 letters." << std::endl;
        } else {
            std::cout << "Incorrect. \"Newfoundland and Labrador\" has 23 letters." << std::endl;
        }
        std::cout << "True or False: Laura Secord was the first female prime minister of Canada. Enter [t] or [f]: ";
        std::cin >> tf1;
        if((tf1 == 'f') || (tf1 == 'F')) {
            carrots += 1;
            std::cout << "Correct! Laura Secord is a chocolate company that was named after the Canadian heroine Laura Secord." << std::endl;
        } else {
            std::cout << "Inorrect. Laura Secord is a chocolate company that was named after the Canadian heroine Laura Secord." << std::endl;
        }
        std::cout << "True or False: Canada is the third largest oil reserve holder in the world. Enter [t] or [f]: ";
        std::cin >> tf2;
        if ((tf2 == 't') || (tf2 == 'T')) {
            carrots += 1;
            std::cout << "Correct! Canada is the third after Venezuela and Saudi Arabia." << std::endl;
        } else {
            std::cout << "Incorrect. Canada is the third after Venezuela and Saudi Arabia." << std::endl;
        }
    }
    
}
