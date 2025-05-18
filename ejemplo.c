/*@
  requires \valid(impuestos);
  requires \is_finite(ingresos);
  requires ingresos >= 0.0f;       // Simplifica la verificación
  assigns *impuestos;

  // Postcondición optimizada (como en tu versión exitosa)
  ensures (ingresos < 6000.0f ==> *impuestos == 0.0f);
  ensures (ingresos >= 6000.0f ==> *impuestos == \round_float(\NearestEven, 0.4f * ingresos));
*/
void calcular_impuestos(float ingresos, float *impuestos) {
    //@ assert \is_finite(ingresos);
    //@ assert ingresos >= 0.0f;

    if (ingresos < 6000.0f) {
        *impuestos = 0.0f;
    } else {
        //@ assert ingresos >= 6000.0f;
        *impuestos = 0.4f * ingresos;  // Usamos 'f' para float literal
    }
}
