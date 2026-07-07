
--------------------------------TABLERO 1--------------------------------
--DW
CREATE DATABASE DW_ProductosDesechado
GO

USE DW_ProductosDesechado
GO

--Tabla DW
CREATE TABLE Desecho (
  Categoria VARCHAR (100) NULL,
  Desecho VARCHAR (100) NULL,
  Cantidad numeric (18,2) NULL,
)
GO

--SP
CREATE PROCEDURE sp_desecho
AS
BEGIN
    DELETE FROM Desecho
    INSERT INTO Desecho (Categoria, Desecho, Cantidad)
    SELECT 
       pc.Name AS CategoriaProducto,
       sr.Name AS RazonDesperdicio,
       SUM(wo.ScrappedQty) AS CantidadDesperdicio
   FROM 
       AdventureWorks2014.Production.WorkOrder wo
       INNER JOIN AdventureWorks2014.Production.Product p 
       ON wo.ProductID = p.ProductID
       INNER JOIN AdventureWorks2014.Production.ProductSubcategory ps 
       ON p.ProductSubcategoryID = ps.ProductSubcategoryID
       INNER JOIN AdventureWorks2014.Production.ProductCategory pc 
       ON ps.ProductCategoryID = pc.ProductCategoryID
       LEFT JOIN AdventureWorks2014.Production.ScrapReason sr 
       ON wo.ScrapReasonID = sr.ScrapReasonID
   WHERE wo.ScrappedQty > 0 
  GROUP BY 
      pc.Name, sr.Name
  ORDER BY 
       pc.Name, CantidadDesperdicio DESC
END
GO

EXEC sp_desecho

--------------------------------TABLERO 2--------------------------------
--DW
CREATE DATABASE DW_VentasTerritorio
GO

USE DW_VentasTerritorio
GO

--Tabla DW
CREATE TABLE comparativo (
  Pais VARCHAR (30) NULL,
  Reales NUMERIC (18,2) NULL, --=?
  Planeadas NUMERIC (18,2) NULL,
)
GO

--SP
CREATE PROCEDURE sp_comparativo
AS
BEGIN
   DELETE FROM comparativo

   INSERT INTO comparativo (Pais, Reales, Planeadas)
   SELECT 
        CASE 
            WHEN t.CountryRegionCode = 'US' THEN 'Estados Unidos'
            WHEN t.CountryRegionCode = 'CA' THEN 'Canadá'
            WHEN t.CountryRegionCode = 'DE' THEN 'Alemania'
            WHEN t.CountryRegionCode = 'FR' THEN 'Francia'
            WHEN t.CountryRegionCode = 'AU' THEN 'Australia'
            WHEN t.CountryRegionCode = 'GB' THEN 'Reino Unido'
            ELSE t.CountryRegionCode   
        END AS Pais,
        SUM(ISNULL(oh.TotalDue, 0)) AS Reales, 
        SUM(ISNULL(t.SalesYTD, 0)) AS Planeadas
   FROM AdventureWorks2014.Sales.SalesTerritory t
   LEFT JOIN AdventureWorks2014.Sales.SalesOrderHeader oh
        ON t.TerritoryID = oh.TerritoryID
   GROUP BY t.CountryRegionCode 
END
GO

EXEC sp_comparativo


--------------------------------TABLERO 3--------------------------------
--DW
CREATE DATABASE DW_VentasProductos
GO

USE DW_VentasProductos
GO

--Tabla DW
CREATE TABLE ventas (
  Idproducto INT NULL,
  Producto VARCHAR (100) NULL,
  Ventas NUMERIC (18,2) NULL,
  Promedio NUMERIC (18,2) NULL,
  Subcategoria VARCHAR (100) NULL,
  Categoria  VARCHAR (100) NULL,
)
GO

--SP
CREATE PROCEDURE sp_ventas
AS
BEGIN
    DELETE FROM ventas
    INSERT INTO ventas (IdProducto, Producto, Ventas, Promedio, Subcategoria, Categoria)
    SELECT 
        p.ProductID,
        p.Name AS Producto,
        SUM(s.LineTotal) AS Ventas,
        AVG(s.LineTotal) AS Promedio,
        ps.Name AS Subcategoria,
        pc.Name AS Categoria
    FROM 
        AdventureWorks2014.Sales.SalesOrderDetail s
        INNER JOIN AdventureWorks2014.Production.Product p 
            ON s.ProductID = p.ProductID
        LEFT JOIN AdventureWorks2014.Production.ProductSubcategory ps 
            ON p.ProductSubcategoryID = ps.ProductSubcategoryID
        LEFT JOIN AdventureWorks2014.Production.ProductCategory pc 
            ON ps.ProductCategoryID = pc.ProductCategoryID
    GROUP BY 
        p.ProductID, p.Name, ps.Name, pc.Name
    HAVING 
        SUM(s.LineTotal) > 1000000
    ORDER BY 
        Categoria, Subcategoria, Producto
END
GO

EXEC sp_ventas