Create Database  ElectroTienda
GO
Use ElectroTienda
GO
Alter authorization on database::ElectroTienda to sa
GO
set dateformat dmy
set language spanish
GO
--Creación de la base de datos--
create table Cliente(
ID_Cliente int not null,
Nombre varchar(30)not null,
Apellido varchar(30)not null,
Dirección varchar(250)not null,
Num_teléfono varchar(9)not null,
Correo_electronico varchar(50)not null,
Constraint [PK_Cliente] Primary key (ID_Cliente ASC)
)
GO
create table Empleado(
ID_Empleado int not null,
Nombre varchar(30)not null,
Apellido varchar(30)not null,
Salario numeric(9,2)not null,
Fec_Ingreso datetime not null,
Constraint [PK_Empleado] Primary key (ID_Empleado ASC)
)
GO
create table Estado(
Código_Estado int not null,
Nombre varchar(30) not null,
Descripción varchar(250) null,
Constraint [PK_Estado] Primary key (Código_Estado ASC)
)
GO
create table Método_de_pago(
Código_Pago int not null,
Nombre varchar(30) not null,
Descripción varchar(250) null,
Constraint [PK_Método_de_pago] Primary key (Código_Pago ASC)
)
GO
create table Factura(
Código_Factura int not null,
Fec_Pedido datetime not null,
ID_Cliente int not null,
ID_Empleado int not null,
Código_Pago int not null,
Código_Estado int not null,
Constraint [PK_Factura] Primary key (Código_Factura ASC),
Constraint FK_Cliente_Factura foreign key (ID_Cliente)
References Cliente(ID_Cliente),
Constraint FK_Estado_Factura foreign key (Código_Estado)
References Estado(Código_Estado),
Constraint FK_Empleado_Factura foreign key (ID_Empleado)
References Empleado(ID_Empleado),
Constraint FK_Método_de_pago_Factura foreign key (Código_Pago)
References Método_de_pago(Código_Pago),
)
GO
create table Factura_Pedido(
Cantidad int not null,
Código_Factura int not null,
Código_Producto int not null,
Constraint FK_Factura_Factura_Pedido foreign key (Código_Factura)
References Factura(Código_Factura),
Constraint FK_Productos_Factura_Pedido foreign key (Código_Producto)
References Productos(Código_Producto),
)
GO
create table Categoría_Producto(
Código_Categoría int not null,
Nombre varchar(30)not null,
Descripción varchar(250) null,
Constraint [PK_Categoría_Producto] Primary key (Código_Categoría ASC)
)
GO
create table Proveedores(
Código_Proveedores int not null,
Nombre varchar(30)not null,
Dirección varchar(250)not null,
Num_teléfono varchar(9)not null,
Constraint [PK_Proveedores] Primary key (Código_Proveedores ASC)
)
GO
create table Promoción(
Código_Promoción int not null,
Descuento varchar(50) not null,
Fec_Inicio datetime null,
Fec_Finalización datetime null,
Constraint [PK_Promoción] Primary key (Código_Promoción ASC)
)
GO
create table Productos(
Código_Producto int not null,
Nombre varchar(50)not null,
Descripción varchar(250) null, 
Precio numeric(9,2)not null,
Stock int not null,
Código_Categoría int not null,
Código_Proveedores int not null,
Código_Promoción int not null,
Constraint [PK_Productos] Primary key (Código_Producto ASC),
Constraint Categoría_Producto_Productos foreign key (Código_Categoría)
References Categoría_Producto(Código_Categoría),
Constraint Proveedores_Productos foreign key (Código_Proveedores)
References Proveedores(Código_Proveedores),
Constraint Promoción_Productos foreign key (Código_Promoción)
References Promoción(Código_Promoción),
)
GO
/* Inserción de los datos.*/
--Insertar datos en la tabla cliente 
INSERT INTO Cliente(ID_Cliente,Nombre,Apellido,Dirección,Num_teléfono,Correo_electronico) VALUES(01,'Aaron','Salazar','Cinco Esquinas,Tibás de San José','8574-8752','AaaronSal@gmail.com') 
INSERT INTO Cliente(ID_Cliente,Nombre,Apellido,Dirección,Num_teléfono,Correo_electronico) VALUES(02,'Santiago','Vargas',',San Miguel,Santo Domingo de Heredia','8054-9632','VargasS11@gmail.com') 
INSERT INTO Cliente(ID_Cliente,Nombre,Apellido,Dirección,Num_teléfono,Correo_electronico) VALUES(03,'María','Alvarado','Santa Lucía,Barva de Heredia','7841-9632','MaríaAlv23@gmail.com') 
INSERT INTO Cliente(ID_Cliente,Nombre,Apellido,Dirección,Num_teléfono,Correo_electronico) VALUES(04,'Carlos','Rojas','San Rafael de Alajuela','6589-1402','carlrojas@gmail.com') 
INSERT INTO Cliente(ID_Cliente,Nombre,Apellido,Dirección,Num_teléfono,Correo_electronico) VALUES(05,'Ana','Carrillo','Los Lagos,San Francisco de Heredia','8430-8524','CarilloAna879@gmail.com') 
INSERT INTO Cliente(ID_Cliente,Nombre,Apellido,Dirección,Num_teléfono,Correo_electronico) VALUES(07,'Juan','Castro','Rincón de Sabanilla, San Pablo de Heredia','8803-5507','CastroJ89@hotmail.com')
INSERT INTO Cliente(ID_Cliente,Nombre,Apellido,Dirección,Num_teléfono,Correo_electronico) VALUES(06,'Jorge','González','Palmares de Alajuela','8974-0163','Jorgego980@outlook.com') 
INSERT INTO Cliente(ID_Cliente,Nombre,Apellido,Dirección,Num_teléfono,Correo_electronico) VALUES(08,'Andrea','Araya','Moravia de San José','7891-3450','ArayaA8673@gmail.com') 
INSERT INTO Cliente(ID_Cliente,Nombre,Apellido,Dirección,Num_teléfono,Correo_electronico) VALUES(09,'Manuel','Chaves','Santo Tomas, Santo Domingo de Heredia','6740-8235','ManuCR@gmail.com') 
INSERT INTO Cliente(ID_Cliente,Nombre,Apellido,Dirección,Num_teléfono,Correo_electronico) VALUES(10,'Carmen','Salazar','San Francisco, San Isidro de Heredia','8689-0021','SalCarmen@hotmail.com') 
GO
--Insertar datos en la tabla Empleado
INSERT INTO Empleado(ID_Empleado,Nombre,Apellido,Salario,Fec_Ingreso) VALUES(10512,'Joseph','Montero',400000,'05/12/2022') 
INSERT INTO Empleado(ID_Empleado,Nombre,Apellido,Salario,Fec_Ingreso) VALUES(20810,'Axel','Barquero',400000,'08/10/2022')
INSERT INTO Empleado(ID_Empleado,Nombre,Apellido,Salario,Fec_Ingreso) VALUES(30708,'Gabriel','Vargas',400000,'07/08/2022')
INSERT INTO Empleado(ID_Empleado,Nombre,Apellido,Salario,Fec_Ingreso) VALUES(40402,'Santiago','Castro',400000,'04/02/2022')
INSERT INTO Empleado(ID_Empleado,Nombre,Apellido,Salario,Fec_Ingreso) VALUES(50507,'Jimena','Carrillo',400000,'05/07/2022')
INSERT INTO Empleado(ID_Empleado,Nombre,Apellido,Salario,Fec_Ingreso) VALUES(62807,'Esteban','Salazar',400000,'28/07/2022')
INSERT INTO Empleado(ID_Empleado,Nombre,Apellido,Salario,Fec_Ingreso) VALUES(71711,'David','Zamora',400000,'17/11/2022')
INSERT INTO Empleado(ID_Empleado,Nombre,Apellido,Salario,Fec_Ingreso) VALUES(81211,'Camila','Rojas',400000,'12/11/2022')
INSERT INTO Empleado(ID_Empleado,Nombre,Apellido,Salario,Fec_Ingreso) VALUES(91905,'Jonathan','Morales',400000,'19/05/2022')
INSERT INTO Empleado(ID_Empleado,Nombre,Apellido,Salario,Fec_Ingreso) VALUES(100406,'Luciana','Mena',400000,'04/06/2022')
GO
--Insertar datos en la table Estado
INSERT INTO Estado(Código_Estado,Nombre,Descripción) VALUES(1,'Pendiente de Confirmación','El pedido se ha sido realizado, pero aún no se ha confirmado la disponibilidad de los productos y la entrega.') 
INSERT INTO Estado(Código_Estado,Nombre,Descripción) VALUES(2,'En Proceso de Preparación','Los productos están siendo preparados para su envío.')
INSERT INTO Estado(Código_Estado,Nombre,Descripción) VALUES(3,'En Espera de Pago','El pedido está a la espera de confirmación de pago antes de ser procesado y enviado.')
INSERT INTO Estado(Código_Estado,Nombre,Descripción) VALUES(4,'En Tránsito','El pedido ha sido enviado y se encuentra en camino hacia la dirección de entrega.')
INSERT INTO Estado(Código_Estado,Nombre,Descripción) VALUES(5,'Entregado','El pedido ha llegado a su destino y ha sido entregado al destinatario.')
INSERT INTO Estado(Código_Estado,Nombre,Descripción) VALUES(6,'Reprogramado','El cliente o la empresa ha solicitado reprogramar la entrega para otro momento.')
INSERT INTO Estado(Código_Estado,Nombre,Descripción) VALUES(7,'Cancelado','El pedido ha sido cancelado por el cliente, la empresa o por alguna otra razón.')
INSERT INTO Estado(Código_Estado,Nombre,Descripción) VALUES(8,'Devuelto','Los productos han sido devueltos por el cliente o no pudieron ser entregados y fueron devueltos al remitente.')
GO
--Insertar datos en la tabla Metodo de pago
INSERT INTO Método_de_pago(Código_Pago,Nombre,Descripción) VALUES(1,'Efectivo','Pago con moneda física.')
INSERT INTO Método_de_pago(Código_Pago,Nombre,Descripción) VALUES(2,'Pago en Línea','Utilización de plataformas en línea para realizar pagos, a menudo a través de tarjetas de crédito o débito.')
INSERT INTO Método_de_pago(Código_Pago,Nombre,Descripción) VALUES(3,'Transferencias Bancarias','Transacción electrónica directa entre cuentas bancarias.')
INSERT INTO Método_de_pago(Código_Pago,Nombre,Descripción) VALUES(4,'Pago por Móvil','Utilización de aplicaciones móviles para realizar pagos')
GO
--Insertar datos en la tabla factura 
INSERT INTO Factura(Código_Factura,Fec_Pedido,ID_Cliente,ID_Empleado,Código_Pago,Código_Estado) VALUES(1,'15/11/2023',01,10512,2,4)
INSERT INTO Factura(Código_Factura,Fec_Pedido,ID_Cliente,ID_Empleado,Código_Pago,Código_Estado) VALUES(2,'16/10/2023',02,20810,2,5)
INSERT INTO Factura(Código_Factura,Fec_Pedido,ID_Cliente,ID_Empleado,Código_Pago,Código_Estado) VALUES(3,'10/12/2023',03,30708,2,2)
INSERT INTO Factura(Código_Factura,Fec_Pedido,ID_Cliente,ID_Empleado,Código_Pago,Código_Estado) VALUES(4,'07/11/2023',04,40402,1,3)
INSERT INTO Factura(Código_Factura,Fec_Pedido,ID_Cliente,ID_Empleado,Código_Pago,Código_Estado) VALUES(5,'20/11/2023',05,50507,2,7)
INSERT INTO Factura(Código_Factura,Fec_Pedido,ID_Cliente,ID_Empleado,Código_Pago,Código_Estado) VALUES(6,'12/12/2023',06,62807,1,1)
INSERT INTO Factura(Código_Factura,Fec_Pedido,ID_Cliente,ID_Empleado,Código_Pago,Código_Estado) VALUES(7,'10/09/2023',07,71711,4,8)
INSERT INTO Factura(Código_Factura,Fec_Pedido,ID_Cliente,ID_Empleado,Código_Pago,Código_Estado) VALUES(8,'05/12/2023',08,81211,2,4)
INSERT INTO Factura(Código_Factura,Fec_Pedido,ID_Cliente,ID_Empleado,Código_Pago,Código_Estado) VALUES(9,'07/12/2023',09,91905,4,4)
INSERT INTO Factura(Código_Factura,Fec_Pedido,ID_Cliente,ID_Empleado,Código_Pago,Código_Estado) VALUES(10,'10/12/2023',10,100406,2,2)
INSERT INTO Factura(Código_Factura,Fec_Pedido,ID_Cliente,ID_Empleado,Código_Pago,Código_Estado) VALUES(11,'07/11/2023',11,91905,2,5)
INSERT INTO Factura(Código_Factura,Fec_Pedido,ID_Cliente,ID_Empleado,Código_Pago,Código_Estado) VALUES(6,'12/12/2023',06,62807,1,1)
GO
--Insertar datos en la tabla Categoria Producto
INSERT INTO Categoría_Producto(Código_Categoría,Nombre) VALUES(1,'Telefonía')
INSERT INTO Categoría_Producto(Código_Categoría,Nombre) VALUES(2,'Informática')
INSERT INTO Categoría_Producto(Código_Categoría,Nombre) VALUES(3,'Electrodomésticos')
GO
--Insertar datos en la tabla Proveedores
INSERT INTO Proveedores(Código_Proveedores,Nombre,Dirección,Num_teléfono) VALUES(1,'Samsung','Costa Rica', '2236-7071')
INSERT INTO Proveedores(Código_Proveedores,Nombre,Dirección,Num_teléfono) VALUES(2,'Apple','Costa Rica','2289 3282')
INSERT INTO Proveedores(Código_Proveedores,Nombre,Dirección,Num_teléfono) VALUES(3,'Asus','Costa Rica','2202-1208')
INSERT INTO Proveedores(Código_Proveedores,Nombre,Dirección,Num_teléfono) VALUES(4,'Logitech','Costa Rica','2249-7284')
INSERT INTO Proveedores(Código_Proveedores,Nombre,Dirección,Num_teléfono) VALUES(5,'Oster','Costa Rica','2548-7004')
GO
--Insertar datos en la tabla Promocion hasta aqui todo insert , hay que insertar de PROMOCION en adelante 
INSERT INTO Promoción(Código_Promoción,Descuento) VALUES(0,'0%')
INSERT INTO Promoción(Código_Promoción,Descuento,Fec_Inicio,Fec_Finalización ) VALUES(1,'10%','01/10/2023','15/10/2023')
INSERT INTO Promoción(Código_Promoción,Descuento,Fec_Inicio,Fec_Finalización ) VALUES(2,'20%','01/12/2023','20/12/2023')
INSERT INTO Promoción(Código_Promoción,Descuento,Fec_Inicio,Fec_Finalización ) VALUES(3,'30%','01/11/2023','10/11/2023')
INSERT INTO Promoción(Código_Promoción,Descuento,Fec_Inicio,Fec_Finalización ) VALUES(4,'50%','20/11/2023','30/11/2023')
GO
--Insertar datos en la tabla Productos HASTA AQUI TODO BIEN 
INSERT INTO Productos(Código_Producto,Nombre,Descripción,Precio,Stock,Código_Categoría,Código_Proveedores,Código_Promoción) VALUES(101,'Samsung Galaxy Z Flip5','Almacenamiento: 512 GB, Sistema Operativo: Android',808800,20,1,1,2 )
INSERT INTO Productos(Código_Producto,Nombre,Descripción,Precio,Stock,Código_Categoría,Código_Proveedores,Código_Promoción) VALUES(102,'IPhone 15 Pro Max','Almacenamiento: 512 GB,Sistema Operativo: Apple',951000,12,1,2,2 )
INSERT INTO Productos(Código_Producto,Nombre,Descripción,Precio,Stock,Código_Categoría,Código_Proveedores,Código_Promoción) VALUES(201,'Monitor Asus VA24EHF','Tamaño: 24 pulgadas, Resolucion: 1920x1080' ,76000,14,2,3,1 )
INSERT INTO Productos(Código_Producto,Nombre,Descripción,Precio,Stock,Código_Categoría,Código_Proveedores,Código_Promoción) VALUES(202,'Teclado Logitech G Pro','Tipo de Teclado: Mecanico ,Cable: USB Extraible',58000,10,2,4,3 )
INSERT INTO Productos(Código_Producto,Nombre,Descripción,Precio,Stock,Código_Categoría,Código_Proveedores,Código_Promoción) VALUES(301,'Microondas Samsung','Capacidad:23L, Alimentación Potencia de salida:750 W',79900,16,3,1,4 )
INSERT INTO Productos(Código_Producto,Nombre,Descripción,Precio,Stock,Código_Categoría,Código_Proveedores,Código_Promoción) VALUES(302,'Freidora De Aire Oster','Capacidad: 6,8L',89900,17,3,5,0 )
GO
--Insertar datos en la tabla factura-pedido
INSERT INTO Factura_Pedido(Cantidad,Código_Factura,Código_Producto) VALUES (1,01,101)
INSERT INTO Factura_Pedido(Cantidad,Código_Factura,Código_Producto) VALUES (1,02,102)
INSERT INTO Factura_Pedido(Cantidad,Código_Factura,Código_Producto) VALUES (1,03,201)
INSERT INTO Factura_Pedido(Cantidad,Código_Factura,Código_Producto) VALUES (1,04,202)
INSERT INTO Factura_Pedido(Cantidad,Código_Factura,Código_Producto) VALUES (1,05,301)
INSERT INTO Factura_Pedido(Cantidad,Código_Factura,Código_Producto) VALUES (1,06,302)
INSERT INTO Factura_Pedido(Cantidad,Código_Factura,Código_Producto) VALUES (1,06,301)
INSERT INTO Factura_Pedido(Cantidad,Código_Factura,Código_Producto) VALUES (1,07,101)
INSERT INTO Factura_Pedido(Cantidad,Código_Factura,Código_Producto) VALUES (1,08,102)
INSERT INTO Factura_Pedido(Cantidad,Código_Factura,Código_Producto) VALUES (1,09,201)
INSERT INTO Factura_Pedido(Cantidad,Código_Factura,Código_Producto) VALUES (1,10,202)
INSERT INTO Factura_Pedido(Cantidad,Código_Factura,Código_Producto) VALUES (1,11,301)
INSERT INTO Factura_Pedido(Cantidad,Código_Factura,Código_Producto) VALUES (1,01,302)
GO
--Consultas solicitadas.--
/*1. Listar todas las facturas de un cliente dado en un Rango de Fechas. Mostrando código y
nombre del cliente, el código del pedido la fecha. Se debe indicar en la consulta el código de
cliente a consultar y el rango de fechas de la consulta.
Página 1 de 2*/
SELECT c.ID_Cliente, c.Nombre AS NombreCliente, f.Código_Factura,Convert(Varchar(10),f.[Fec_Pedido],103) AS [Fec_Pedido] 
  FROM [dbo].[Factura] f
  INNER JOIN Cliente c ON f.ID_Cliente = c.ID_Cliente
  WHERE f.ID_Cliente = '01'
        AND f.Fec_Pedido BETWEEN '01/11/2023' AND '29/11/2023';
GO
/*2. Listar todos los productos de una factura en específico. Mostrando código y fecha de la
factura, el código, nombre del producto y cantidad facturada. Se debe indicar en la consulta
el código de la factura a consultar.*/
SELECT fp.Código_Factura,Convert(Varchar(10),f.[Fec_Pedido],103) AS [Fec_Pedido] , p.Código_Producto, p.Nombre AS Nombre_Producto,fp.Cantidad
   FROM [dbo].[Factura_Pedido] fp
   INNER JOIN Factura f ON fp.Código_Factura = f.Código_Factura
   INNER JOIN Productos p ON fp.Código_Producto = p.Código_Producto
   WHERE fp.Código_Factura = '06';
GO
/*3. Desplegar el monto vendido entre un rango de fechas por método de pago. En la consulta se
debe indicar el rango de fechas de la consulta*/
SELECT m.Nombre AS Metodo_Pago, SUM(p.Precio * fp.Cantidad) AS Monto_Vendido
FROM [dbo].[Factura] f
   INNER JOIN Factura_Pedido fp ON f.Código_Factura = fp.Código_Factura
   INNER JOIN Productos p ON fp.Código_Producto = p.Código_Producto
   INNER JOIN Método_de_pago m ON f.Código_Pago = m.Código_Pago
   WHERE f.Fec_Pedido BETWEEN '01/11/2023' AND '01/12/2023'
   Group by m.Nombre;
GO
/*4. Mostrar la cantidad de facturas realizadas en un Rango de Fechas. Se debe mostrar la
cantidad de facturas, y la fecha. En la consulta se debe indicar el rango de fechas de la
consulta.*/
SELECT COUNT(*) AS Cantidad_Facturas,Convert(Varchar(10),[Fec_Pedido],103) AS [Fec_Pedido]
  FROM [dbo].[Factura]
  WHERE Fec_Pedido BETWEEN '01/10/2023' AND '20/12/2023'
  Group by [Fec_Pedido]
go
/*5. Mostar para cada categoría el costo total de los productos asociados, el promedio, el
mínimo y el máximo. Mostrar el código de la categoría y los montos solicitados*/
SELECT cp.Código_Categoría, cp.Nombre AS Categoria, SUM(p.Precio) AS CostoTotal, AVG(p.Precio) AS Promedio, MIN(p.Precio) AS Minimo, MAX(p.Precio) AS Maximo
  FROM [dbo].[Productos] p
  INNER JOIN Categoría_Producto cp ON p.Código_Categoría = cp.Código_Categoría
  GROUP BY cp.Código_Categoría, cp.Nombre;
GO

/*Consultas adicionales*/
SELECT
    f.Código_Factura,
    f.Fec_Pedido,
    c.ID_Cliente,
    c.Nombre AS NombreCliente,
    c.Apellido AS ApellidoCliente,
    c.Dirección AS DirecciónCliente,
    c.Num_teléfono AS TeléfonoCliente,
    c.Correo_electronico AS CorreoCliente,
    e.ID_Empleado,
    e.Nombre AS NombreEmpleado_Asociado,
    m.Código_Pago,
    m.Nombre AS MetodoPago,
    es.Código_Estado,
    es.Nombre AS Estado
FROM Factura f
    INNER JOIN Cliente c ON f.ID_Cliente = c.ID_Cliente
    INNER JOIN Empleado e ON f.ID_Empleado = e.ID_Empleado
    INNER JOIN Método_de_pago m ON f.Código_Pago = m.Código_Pago
    INNER JOIN Estado es ON f.Código_Estado = es.Código_Estado
WHERE
    f.Código_Factura = '01';
GO
-----------
SELECT
    fp.Cantidad, 
    p.Código_Producto,
    p.Nombre AS NombreProducto,
    p.Precio AS PrecioProducto,
    p.Stock AS StockProducto,
    cat.Código_Categoría,
    cat.Nombre AS NombreCategoria,
    pro.Código_Proveedores,
    pro.Nombre AS NombreProveedor,
    pro.Dirección AS DirecciónProveedor,
    pro.Num_teléfono AS TeléfonoProveedor
FROM
    Factura_Pedido fp
    INNER JOIN Productos p ON fp.Código_Producto = p.Código_Producto
    INNER JOIN Categoría_Producto cat ON p.Código_Categoría = cat.Código_Categoría
    INNER JOIN Proveedores pro ON p.Código_Proveedores = pro.Código_Proveedores
WHERE
    fp.Código_Factura = 1;
GO