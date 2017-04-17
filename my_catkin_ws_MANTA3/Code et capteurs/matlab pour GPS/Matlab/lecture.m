function lecture
clear ;
clc ;

%%%initialisation
T = [];
posE = [] ;
posN = [] ;

%%%OUVERTURE FICHIER
id = fopen('results.txt');

%%%ÉCRITURE DES MATRICES
while ~feof(id)
    textscan(id,'T');
    T = [T, cell2mat(textscan(id,'%f'))] ;
    
    textscan(id,'GPS');
    pos_depart = cell2mat(textscan(id,'%f'));
    posE = [posE, pos_depart(1)] ;
    posN = [posN, pos_depart(2)] ;
    
    textscan(id,'OR');
    textscan(id,'%f');
    
    textscan(id,'DI');
    textscan(id,'%f');
end

posE = 10^(-3)*posE ;
posN = 10^(-3)*posN ;

trace_carte(posN,posE,T)