[top]
components : cajero@Cajero
in : detectoPase yaSalio monedas
out : devolver pago multar
Link : detectoPase detectoPase@cajero
Link : yaSalio yaSalio@cajero
Link : monedas monedas@cajero
Link : devolver@cajero devolver
Link : pago@cajero pago
Link : multar@cajero multar

[cajero]
cantMonedas5 : 2
cantMonedas10 : 4
cantMonedas50 : 6
cantMonedas100 : 7
costoPeaje : 0.70