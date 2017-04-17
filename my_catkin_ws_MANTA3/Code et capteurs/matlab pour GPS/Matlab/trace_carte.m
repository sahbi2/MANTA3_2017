function trace_carte(posN,posE,T)

%%%cadrage
marge = 0.0003 ;

MIN_LON = min(posE) -marge;
MAX_LON = max(posE) +marge;

MIN_LAT = min(posN) -marge;
MAX_LAT = max(posN) +marge;


%%%traçage
m_proj('albers equal-area','long',[MIN_LON MAX_LON],'lat',[MIN_LAT MAX_LAT]);
m_grid;
m_track(posE,posN,'ticks',0,'times',4,'dates',8,...
        'clip','off','color','r','orient','upright');
