//Phase post viser
void physique(){
  // if (balle.y > LCDHEIGHT) { mode = 'v'; init(); }
  t += 0.1;
  balle.x =  FViser * cos(NViser) *  t + IBallex;
  balle.y = (0.5)*10*t*t + FViser * sin(NViser) * t + IBalley;
  Serial.println("?");
  Serial.println(t);
}

/*
 *  PFD
 *  f = m*A
 *  f = p = m*g
 *  Ay = g
 *  Ax = A0
 *  On intègre
 *  Vx = A0 * t + FViser * cos(NViser)
 *  Vy = g*t + FViser*sin(NViser)
 *  encore
 *  Xx = FViser * cos(NViser) * t
 *  Xy = (1/2)*sq(t) +  FViser * sin(NViser) * t + IBalley;
 * 
 */

