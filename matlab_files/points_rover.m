function [P1, P2, P3, P4, P5, P6, P7, P8, P9] = points_rover(Pbase, width, dimentions)
    %defining dimentions
    LP1toP2 = dimentions(1);
    LP2toP3 = dimentions(2);
    LP3toP4 = dimentions(3);
    LP4toP5 = dimentions(4);
    LP5toP6 = dimentions(5);
    LP6toP7 = dimentions(6);
    LP7toP8 = dimentions(7);
    LP8toP1 = dimentions(8);

    %intermediate points
    LP5toP9 = 0.105;
    LP9toP6 = 0.235;

    LP7toP10 = 0.265;
    LP10toP8 = 0.105;

    TPbasetoP1 = [1 0 0  0.135;
                  0 1 0 -width/2;
                  0 0 1 -LP6toP7;
                  0 0 0  1];

    %translation z
    TP1toP2 = [1 0 0 0;
               0 1 0 0;
               0 0 1 LP1toP2;
               0 0 0 1];

    %translation x
    TP2toP3 = [1 0 0 -LP2toP3;
               0 1 0  0;
               0 0 1  0;
               0 0 0  1];

    %translation z
    TP3toP4 = [1 0 0 0;
               0 1 0 0;
               0 0 1 LP3toP4;
               0 0 0 1];

    %translation x
    TP4toP5 = [1 0 0 -LP4toP5;
               0 1 0  0;
               0 0 1  0;
               0 0 0  1];

    %translation x and z
    TP5toP6 = [1 0 0 -LP9toP6;
               0 1 0  0;
               0 0 1 -LP5toP9;
               0 0 0  1];

    %translation z
    TP5toP9 = [1 0 0  0;
               0 1 0  0;
               0 0 1 -LP5toP9;
               0 0 0  1];

    %translation z
    TP6toP7 = [1 0 0  0;
               0 1 0  0;
               0 0 1 -LP6toP7;
               0 0 0  1];

    %translation x and z
    TP7toP8 = [1 0 0  LP7toP10;
               0 1 0  0;
               0 0 1 -LP10toP8;
               0 0 0  1];

    %translation x
    TP8toP1 = [1 0 0 LP8toP1;
               0 1 0 0;
               0 0 1 0;
               0 0 0 1];

    P1 = Pbase * TPbasetoP1;
    P2 = P1 * TP1toP2;
    P3 = P2 * TP2toP3;
    P4 = P3 * TP3toP4;
    P5 = P4 * TP4toP5;
    P6 = P5 * TP5toP6;
    P7 = P6 * TP6toP7;
    P8 = P7 * TP7toP8;
    P9 = P5 * TP5toP9;
end
