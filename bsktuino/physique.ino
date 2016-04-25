//Phase post viser
void physique(){
  if (balle.y > LCDHEIGHT) { mode = 'v'; }
  t += 1;
  balle.x = t;
  balle.y = -(1/2)*sq(t) +  FViser * sin(NViser) * t + IBalley;
}

/*
 *  PFD
 *  f = m*A
 *  f = p = m*g
 *  A = g
 *  On intègre
 *  Vy = g*t + FViser*sin(NViser)
 *  encore
 *  Xy = (1/2)*sq(t) +  FViser * sin(NViser) * t + IBalley;
 * 
 */
