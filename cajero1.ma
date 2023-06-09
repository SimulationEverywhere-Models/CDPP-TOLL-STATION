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
cantMonedas5 : 100
cantMonedas10 : 100
cantMonedas50 : 100
cantMonedas100 : 100
costoPeaje : 1.30