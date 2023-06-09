[top]
components : cajero@Cajero cola@Cola genPago@GenPago sensor@Sensor control@Control lector@Lector barrera@Barrera genAutos@GenAutos timer@Timer
out : monedas log
Link : devolver@cajero monedas
Link : logInfo@control log
Link : detecto@lector detectoPase@cajero
Link : detecto@sensor yaSalio@cajero
Link : detecto@sensor yaSalio@cola
Link : detecto@sensor yaSalio@control
Link : detecto@sensor bajar@barrera
Link : pago@cajero pago@control
Link : multar@cajero multar@control
Link : saleAuto@cola yaEntro@control
Link : saleAuto@cola generar@genPago
Link : levantarBarrera@control levantar@barrera
Link : levantarBarrera@control paso@sensor
Link : automovil@genAutos llegaAuto@cola
Link : monedas@genPago monedas@cajero
Link : pase@genPago paso@lector
Link : timeout@timer timeout@control

[cajero]
cantMonedas5 : 100
cantMonedas10 : 100
cantMonedas50 : 100
cantMonedas100 : 100
costoPeaje : 0.20

[genAutos]
distribucion : poisson 
mean : 60

[timer]
activeTime : 1:0:0:0

[genPago]
probabilidadPase : 0.00