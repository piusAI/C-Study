
int main(){
    ColorPoint cp;
    ColorPoint *pDer;
    Point* pBase = pDer; // upcasting


    pDer->set(3,4);
    pBase->showPoint();

    
    pDer->(ColorPoint *) pBase; //downCasting
    pDer->setColor("Red"); //compile!
    pDer->showColorPoint(); //Compile!
}
