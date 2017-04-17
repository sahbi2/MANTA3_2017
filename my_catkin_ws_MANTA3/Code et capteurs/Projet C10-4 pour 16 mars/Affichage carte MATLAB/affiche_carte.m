function affiche_carte (posE,posN,OR,D1,D2,D3) %affiche le robot + son orientation + les obstaches vus
x=[0:pi/50:2*pi]';
a=5; b=2; c=6;
%affichage robot
ab=pi/2-OR(end);
plot(posE(end)+a*cos(x)*cos(ab)-b*sin(x)*sin(ab),posN(end)+a*cos(x)*sin(ab)+b*sin(x)*cos(ab)); hold on;
%affichage orientation
plot([posE(end);posE(end)+c*sin(OR(end))],[posN(end);posN(end)+c*cos(OR(end))],'g'); hold on;
%affichage des 3 distances
plot(posE(end)-D1(end)*cos(OR(end)),posN(end)+D1(end)*sin(OR(end)),'+r'); hold on; 
plot(posE(end)+D2(end)*sin(OR(end)),posN(end)+D2(end)*cos(OR(end)),'+r'); hold on; 
plot(posE(end)+D3(end)*cos(OR(end)),posN(end)-D3(end)*sin(OR(end)),'+r'); hold on;