boolean run;
int running = 8;
int runningstate = digitalRead(running);
int beforerunningstate = digitalRead(running);
int count = 0;
int hundrethofsec = 0;
void setup () {
  pinMode(running,INPUT);  
}
void runningfunction () {
  runningstate = digitalRead(running);
  if (!(runningstate == beforerunningstate)){
    run = false;
  }
  else {
    run = true;
  }
}

void loop () {
  beforerunningstate = digitalRead(running);
  runningfunction();
  beforerunningstate = digitalRead(running);
  if (run == true) {
    count = 24;
    hundrethofsec = 0;
  }
  else {
  if (count == 24 && hundrethofsec == 0) {
    count = 14;
  }
  else {
    count = 24;
    hundrethofsec = 0;
  }
  }

  while(true) {
  run = false;
  count = 24;
  hundrethofsec = 0;
  while(true) {
  runningfunction();
  beforerunningstate = digitalRead(running);
  while(run == false) {
  runningfunction();
  beforerunningstate = digitalRead(running);
    if (run == true) {
      break;
    }
  }
    hundrethofsec = hundrethofsec + 1;
    delay(1000);
    if (hundrethofsec == 100) {
      hundrethofsec = 0;
      count = count - 1;
      if (count == 0) {
        
      }
    }
  }
    
  }
  }
