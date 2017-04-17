function [posE,posN] = distanceGPS(lon1,lon2,lat1,lat2,OR)
%rayon terre a 48N : 6367km
R = 6367000;
dlon = (lon2 - lon1)/1000; %les donnees GPS sont multipliees par 100
dlat = (lat2 - lat1)/1000;
a = (sin(dlat/2))^2 + cos(lat1) * cos(lat2) * (sin(dlon/2))^2;
c = 2 * atan2(sqrt(a), sqrt(1-a));
d = R * c;
posE=d*sin(OR); posN=d*cos(OR);