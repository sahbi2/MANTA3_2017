close all; clear all;

%%%OUVERTURE FICHIER
id=fopen('trajectoire_et_carte.txt');
textscan(id,'T');
[Ttemp]=cell2mat(textscan(id,'%f'));
%le repere utilisé sera centre sur la position GPS de depart
textscan(id,'GPS');
[pos_depart]=cell2mat(textscan(id,'%f')); posEtemp=0; posNtemp=0;
textscan(id,'OR');
[ORtemp]=cell2mat(textscan(id,'%f'));
textscan(id,'DI');
[Dtemp]=cell2mat(textscan(id,'%f'));D1temp=Dtemp(1);D2temp=Dtemp(2);D3temp=Dtemp(3);

%%INITIALISATION MATRICES
T=[Ttemp]; %matrice contenant les temps
posE=[posEtemp]; posN=[posNtemp]; %matrices contenant les positions successives du robot
OR=[ORtemp]; %orientation du robot en radians par rapport au nord
D1=[D1temp]; D2=[D2temp]; D3=[D3temp]; %distances obstacles

%%AFFICHAGE
affiche_carte(posE,posN,OR,D1,D2,D3); %affichage de la position initiale
%axis([2215 2230 48710 48720]);
axis equal;
pause;

while ~feof(id)
    %%%LECTURE FICHIER
    textscan(id,'T');
    [Ttemp]=cell2mat(textscan(id,'%f'));
    textscan(id,'GPS');
    [postemp]=cell2mat(textscan(id,'%f'));
    textscan(id,'OR');
    [ORtemp]=cell2mat(textscan(id,'%f'));
    %position GPS par rapport à la position de depart en utilisant distance
    %en metres et orientation
    [posEtemp,posNtemp]=distanceGPS(pos_depart(1),postemp(1),pos_depart(2),postemp(2),ORtemp);
    textscan(id,'DI');
    [Dtemp]=cell2mat(textscan(id,'%f'));D1temp=Dtemp(1);D2temp=Dtemp(2);D3temp=Dtemp(3);

    %%REMPLISSAGE MATRICES
    T=[T Ttemp];
    posE=[posE posEtemp]; posN=[posN posNtemp];
    OR=[OR ORtemp];
    D1=[D1 D1temp]; D2=[D2 D2temp]; D3=[D3 D3temp];
    
    %%AFFICHAGE
    affiche_carte(posE,posN,OR,D1,D2,D3);
    %trajectoire du robot
    plot([posE(end-1);posE(end)],[posN(end-1);posN(end)],'-'); hold on;
    pause;
end