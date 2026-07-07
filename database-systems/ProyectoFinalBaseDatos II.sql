/*Proyecto Base de datos II*/

CREATE DATABASE bdBiblioteca
GO

USE bdBiblioteca
GO

/** INSTRUCCION QUE PERMITE CREAR LOS DIAGRAMAS**/
ALTER AUTHORIZATION ON DATABASE::bdBiblioteca TO sa 
GO
/*Establece el formato de la fecha en día/mes/año*/
SET DATEFORMAT dmy
SET LANGUAGE spanish
GO

/* Creación de las tablas */
CREATE TABLE EDITORIAL (
    idEditorial INT NOT NULL,
    Nombre VARCHAR(50) NOT NULL,
    Direccion VARCHAR(200),
    CONSTRAINT PK_Editorial PRIMARY KEY (idEditorial)
)
GO

CREATE TABLE GENERO (
    idGenero INT NOT NULL,
    Nombre VARCHAR(50) NOT NULL,
    CONSTRAINT PK_Genero PRIMARY KEY (idGenero)
)
GO

CREATE TABLE AUTOR (
    idAutor INT NOT NULL,
    Nombre VARCHAR(50) NOT NULL,
    CONSTRAINT PK_Autor PRIMARY KEY (idAutor)
)
GO

CREATE TABLE LIBRO (
    idLibro INT NOT NULL,
    Titulo VARCHAR(50) NOT NULL,
    NumeroDeISBN VARCHAR(20) NOT NULL,
    AñoPublicacion INT NOT NULL,
    CantidadDias INT NOT NULL,
    Disponibilidad TINYINT NOT NULL, 
    idGenero INT NOT NULL,
    idEditorial INT NOT NULL,
    idAutor INT NOT NULL,
    CONSTRAINT PK_Libros PRIMARY KEY (idLibro),
    CONSTRAINT UQ_NumeroDeISBN UNIQUE (NumeroDeISBN),
    CONSTRAINT FK_Libros_Genero FOREIGN KEY (idGenero) REFERENCES Genero (idGenero),
    CONSTRAINT FK_Libros_Editorial FOREIGN KEY (idEditorial) REFERENCES Editorial (idEditorial),
    CONSTRAINT FK_Libros_Autor FOREIGN KEY (idAutor) REFERENCES Autor (idAutor)
)
GO

CREATE TABLE ESPECIALIDAD (
    idEspecialidad INT NOT NULL,
    Nombre VARCHAR(50) NOT NULL,
    CONSTRAINT PK_Especialidad PRIMARY KEY (idEspecialidad)
)
GO

CREATE TABLE LIBROESPECIALIDAD (
    idLibro INT NOT NULL,
    idEspecialidad int NOT NULL,
    CONSTRAINT PK_LibroEspecialidad PRIMARY KEY (idLibro, idEspecialidad),
    CONSTRAINT FK_LibroEspecialidad_Libros FOREIGN KEY (idLibro) REFERENCES Libro (idLibro),
    CONSTRAINT FK_LibroEspecialidad_Especialidad FOREIGN KEY (idEspecialidad) REFERENCES Especialidad (idEspecialidad)
)
GO

CREATE TABLE CARRERA (
    idCarrera INT NOT NULL,
    Nombre VARCHAR(50) NOT NULL,
    CONSTRAINT PK_Carrera PRIMARY KEY (idCarrera)
)
GO

CREATE TABLE USUARIO (
    idUsuario INT NOT NULL,
    NombreCompleto VARCHAR(100) NOT NULL,
    IdentificacionEstudiantil VARCHAR(50) NOT NULL,
    CorreoElectronico VARCHAR(100) NOT NULL,
    Telefono VARCHAR(9),
    idCarrera INT NOT NULL,
    CONSTRAINT PK_Usuario PRIMARY KEY (idUsuario),
    CONSTRAINT UQ_Usuario_NumeroIdentificacion UNIQUE (IdentificacionEstudiantil),
    CONSTRAINT UQ_Usuario_CorreoElectronico UNIQUE (CorreoElectronico),
    CONSTRAINT FK_Usuario_Carrera FOREIGN KEY (idCarrera) REFERENCES Carrera (idCarrera)
)
GO

CREATE TABLE PERSONALBIBLIOTECA (
    idEmpleado INT NOT NULL,
    NombreCompleto VARCHAR(150) NOT NULL,
    Cargo VARCHAR(50) NOT NULL,
    CorreoElectronico VARCHAR(100) NOT NULL,
    Telefono VARCHAR(9),
    CONSTRAINT PK_PersonalBiblio PRIMARY KEY (idEmpleado),
    CONSTRAINT UQ_PersonalBiblio_Correo UNIQUE (CorreoElectronico)
)
GO

CREATE TABLE PRESTAMO (
    idPrestamo INT NOT NULL,
    FechaDevolucion DATE,
    FechaPrestamo DATE NOT NULL,
    idLibro INT NOT NULL,
    idUsuario INT NOT NULL,
    idEmpleado INT NOT NULL,
    CONSTRAINT PK_Prestamos PRIMARY KEY (idPrestamo),
    CONSTRAINT FK_Prestamos_Libros FOREIGN KEY (idLibro) REFERENCES Libro (idLibro),
    CONSTRAINT FK_Prestamos_Usuario FOREIGN KEY (idUsuario) REFERENCES Usuario (idUsuario),
    CONSTRAINT FK_Prestamos_Empleado FOREIGN KEY (idEmpleado) REFERENCES PersonalBiblioteca (idEmpleado)
)
GO

CREATE TABLE MULTA (
    idMulta INT NOT NULL,
    FechaGeneracion DATE NOT NULL,
    FechaCancelacion DATE,
    CantDiasAtraso INT NOT NULL,
    MontoDiario DECIMAL(10, 2) NOT NULL,
    MontoTotal  DECIMAL(10, 2) NOT NULL,
    Estado VARCHAR(50) NOT NULL,
    idPrestamo INT NOT NULL,
    CONSTRAINT PK_Multa PRIMARY KEY (idMulta),
    CONSTRAINT FK_Multa_Prestamos FOREIGN KEY (idPrestamo) REFERENCES Prestamo (idPrestamo)
)
GO


-- Insertar datos en EDITORIAL
INSERT INTO EDITORIAL (idEditorial, Nombre, Direccion) VALUES 
(1, 'Editorial Alfa', 'Calle 1, Ciudad A'),
(2, 'Editorial Beta', 'Avenida 2, Ciudad B'),
(3, 'Editorial Gamma', 'Boulevard 3, Ciudad C'),
(4, 'Editorial Delta', 'Calle 4, Ciudad D'),
(5, 'Editorial Épsilon', 'Avenida 5, Ciudad E')
GO
-- Insertar datos en GENERO
INSERT INTO GENERO (idGenero, Nombre) VALUES
(1, 'Ficción'),
(2, 'Ciencia'),
(3, 'Historia'),
(4, 'Arte'),
(5, 'Filosofía')
GO
-- Insertar datos en AUTOR
INSERT INTO AUTOR (idAutor, Nombre) VALUES
(1, 'Gabriel García Márquez'),
(2, 'Isaac Asimov'),
(3, 'Yuval Noah Harari'),
(4, 'Frida Kahlo'),
(5, 'Sócrates')
GO
-- Insertar datos en LIBRO
INSERT INTO LIBRO (idLibro, Titulo, NumeroDeISBN, AñoPublicacion, CantidadDias, Disponibilidad, idGenero, idEditorial, idAutor) VALUES
(1, 'Cien años de soledad', '9781234567897', 1967, 15, 1, 1, 1, 1),
(2, 'Fundación', '9782345678910', 1951, 10, 1, 2, 2, 2),
(3, 'Sapiens', '9783456789123', 2014, 20, 1, 3, 3, 3),
(4, 'Mi vida en el arte', '9784567891234', 1939, 5, 1, 4, 4, 4),
(5, 'Diálogos', '9785678912345', 399, 30, 0, 5, 5, 5),
(6, 'Libro de Prueba', '1234567890', 2020, 7, 1, 1, 1, 1)
GO
-- Insertar datos en ESPECIALIDAD
INSERT INTO ESPECIALIDAD (idEspecialidad, Nombre) VALUES
(1, 'Literatura'),
(2, 'Física'),
(3, 'Antropología'),
(4, 'Pintura'),
(5, 'Ética')
GO
-- Insertar datos en LIBROESPECIALIDAD
INSERT INTO LIBROESPECIALIDAD (idLibro, idEspecialidad) VALUES
(1, 1),
(2, 2),
(3, 3),
(4, 4),
(5, 5),
(6, 1)
GO
-- Insertar datos en CARRERA
INSERT INTO CARRERA (idCarrera, Nombre) VALUES
(1, 'Ingeniería en Sistemas'),
(2, 'Medicina'),
(3, 'Arquitectura'),
(4, 'Derecho'),
(5, 'Filosofía')
GO
-- Insertar datos en USUARIO
INSERT INTO USUARIO (idUsuario, NombreCompleto, IdentificacionEstudiantil, CorreoElectronico, Telefono, idCarrera) VALUES
(1, 'Juan Pablo Alvarado', '1234567890', 'juan.pablo@example.com', '8821-2103', 1),
(2, 'Ana Gómez', '2345678901', 'ana.gomez@example.com', '8820-1567', 2),
(3, 'Erik Saborio', '3456789012', 'Erik.Saborio@example.com', '7523-9922', 3),
(4, 'Marta Rojas', '4567890123', 'marta.rojas@example.com', '8304-6732', 4),
(5, 'Carlos Silva', '5678901234', 'carlos.silva@example.com', '8279-0984', 5),
(6, ' Andres Alvarado', '6734901234', 'Andres.alva@example.com', '8049-9484', 3),
(7, ' Steven Vargas', '8734901234', 'Steven.varg@example.com', '7849-8594', 3)
GO
-- Insertar datos en PERSONALBIBLIOTECA
INSERT INTO PERSONALBIBLIOTECA (idEmpleado, NombreCompleto, Cargo, CorreoElectronico, Telefono) VALUES
(1, 'María López', 'Bibliotecario', 'maria.lopez@example.com', '8105-7839'),
(2, 'Pedro Martínez', 'Auxiliar', 'pedro.martinez@example.com', '7204-2564'),
(3, 'Clara Ramírez', 'Coordinador', 'clara.ramirez@example.com', '8922-5522'),
(4, 'José Fernández', 'Archivista', 'jose.fernandez@example.com', '8820-2299'),
(5, 'Lucía González', 'Bibliotecario', 'lucia.gonzalez@example.com', '8842-6833')
GO
-- Insertar datos en PRESTAMO
INSERT INTO PRESTAMO (idPrestamo, FechaDevolucion, FechaPrestamo, idLibro, idUsuario, idEmpleado) VALUES
(1, '2024-11-30', '2024-11-15', 1, 1, 1),
(2, '2024-12-10', '2024-11-20', 2, 2, 2),
(3, '2024-12-05', '2024-11-25', 3, 3, 3),
(4, '2024-12-01', '2024-11-28', 4, 4, 4),
(5, '2024-12-20', '2024-12-29', 5, 5, 5),
(6, '2024-12-26', '2024-12-01', 4, 2, 3),
(7, NULL, '2024-11-25', 1, 7, 5)

GO

-- Insertar datos en MULTA
INSERT INTO MULTA (idMulta, FechaGeneracion, FechaCancelacion, CantDiasAtraso, MontoDiario, MontoTotal, Estado, idPrestamo) VALUES
(1, '2024-12-01', NULL, 5, 1.50, 7.50, 'Pendiente', 1),
(2, '2024-12-11', NULL, 3, 2.00, 6.00, 'Pendiente', 2),
(3, '2024-12-06','2024-12-10', 2, 1.00, 2.00, 'Pagada', 3),
(4, '2024-12-16', NULL, 7, 1.20, 8.40, 'Pendiente', 4),
(5, '2024-12-21', NULL, 4, 2.50, 10.00, 'Pendiente', 5),
(6, '2024-12-21','2024-12-25', 4, 2.50, 10.00, 'Pagada', 6)
GO


/*Desarrolle una Vista que liste los datos del préstamo, datos del libro y datos del alumno de los 
préstamos que cuya fecha de entrega ya se ha vencido. (10 pts)*/
CREATE VIEW Vista_PrestamosVencidos AS
SELECT 
    P.idPrestamo,P.FechaPrestamo,P.FechaDevolucion,
    L.idLibro,L.Titulo,L.NumeroDeISBN,
    U.idUsuario,U.NombreCompleto,U.IdentificacionEstudiantil,
    U.CorreoElectronico
FROM 
    PRESTAMO P
INNER JOIN LIBRO L ON P.idLibro = L.idLibro
INNER JOIN USUARIO U ON P.idUsuario = U.idUsuario
WHERE 
    P.FechaDevolucion < GETDATE() 
GO

SELECT * FROM Vista_PrestamosVencidos
GO


/*Función que reciba el id del alumno y retorne la cantidad de libros que tiene vencidos. (10 p) */
CREATE FUNCTION fn_CantidadLibrosVencidos ( @idUsuario INT)
RETURNS INT
AS
BEGIN
    DECLARE @CantidadVencidos INT

    SELECT @CantidadVencidos = COUNT(*)
    FROM PRESTAMO p
    WHERE p.idUsuario = @idUsuario
    AND p.FechaDevolucion < GETDATE()  
    
    RETURN @CantidadVencidos
END
GO

SELECT dbo.fn_CantidadLibrosVencidos(1)  AS LibrosVencidos;
GO

/*Función que muestre el monto total de las multas, en un rango de fechas en particular. Recibiendo por parámetros las fechas de las multas. (10 pts*/
CREATE FUNCTION fn_MontoTotalMultas ( @FechaInicio DATE, @FechaFin DATE )
RETURNS DECIMAL(10, 2)
AS
BEGIN
    DECLARE @MontoTotal DECIMAL(10, 2);

    SELECT @MontoTotal = SUM(M.MontoTotal)
    FROM MULTA M
    WHERE M.FechaGeneracion BETWEEN @FechaInicio AND @FechaFin  
    AND M.Estado = 'Pendiente'

    RETURN @MontoTotal;
END
GO

SELECT dbo.fn_MontoTotalMultas('2024-12-01', '2024-12-15') AS MontoTotalMultas
GO

/*Procedimiento almacenado que permita registrar un préstamo, recibiendo los parámetros 
mínimos requeridos. (20 pts)a.Validar que el libro no se encuentre prestado. Validar que el 
estudiante no tenga multas sinpagar, o libros pendientes de entregar y cuyo plazo de entrega ya se 
haya cumplido, entreotros aspectos.  (10 pts).b.Registrar el préstamo del libro. (5 pts)c.Uso de 
Try Catch y Transacciones. (2,5 pts)d.Cambio del Estado del Libro a prestado. (2,5 pts)*/

CREATE PROCEDURE pa_REGISTRAR_PRESTAMO
    @idLibro INT,
    @idUsuario INT,
    @FechaPrestamo DATE,
    @FechaDevolucion DATE,
    @idEmpleado INT
AS
BEGIN
    DECLARE @MENSAJE VARCHAR(100)
    DECLARE @Disponible TINYINT
    DECLARE @MontoTotal DECIMAL(10, 2)
    DECLARE @LibrosPendientes INT
    DECLARE @idPrestamo INT

    BEGIN TRY
        -- Obtener el próximo idPrestamo
        SELECT @idPrestamo = ISNULL(MAX(idPrestamo), 0) + 1
        FROM PRESTAMO;

        -- Verificar si el libro ya está prestado
        SELECT @Disponible = Disponibilidad
        FROM LIBRO
        WHERE idLibro = @idLibro;

        IF @Disponible = 0
        BEGIN
            SET @MENSAJE = 'El libro ya está prestado.';
            THROW 56000, @MENSAJE, 10 
        END

        -- Verificar si el estudiante tiene multas no pagadas
        SELECT @MontoTotal = SUM(MontoTotal)
        FROM MULTA
        WHERE idPrestamo IN (SELECT idPrestamo FROM PRESTAMO WHERE idUsuario = @idUsuario)
        AND Estado = 'Pendiente';

        IF @MontoTotal > 0
        BEGIN
            SET @MENSAJE = 'El estudiante tiene multas pendientes de pago.';
            THROW 56000, @MENSAJE, 10 
        END

        -- Verificar si el estudiante tiene libros vencidos no entregados
        SELECT @LibrosPendientes = COUNT(*)
        FROM PRESTAMO p
        WHERE p.idUsuario = @idUsuario
        AND p.FechaDevolucion < GETDATE()  
        AND p.FechaDevolucion IS NOT NULL
        AND p.idPrestamo NOT IN (SELECT idPrestamo FROM MULTA WHERE Estado = 'Pagada'); 

        IF @LibrosPendientes > 0
        BEGIN
            SET @MENSAJE = 'El estudiante tiene libros vencidos sin entregar.';
            THROW 56000, @MENSAJE, 10 
        END

        -- Registrar el préstamo
        INSERT INTO PRESTAMO (idPrestamo, FechaPrestamo, FechaDevolucion, idLibro, idUsuario, idEmpleado)
        VALUES (@idPrestamo, @FechaPrestamo, @FechaDevolucion, @idLibro, @idUsuario, @idEmpleado);

        -- Cambiar el estado del libro a "prestado"
        UPDATE LIBRO
        SET Disponibilidad = 0  
        WHERE idLibro = @idLibro;

    END TRY
    BEGIN CATCH
        THROW
    END CATCH
END
GO



EXEC pa_REGISTRAR_PRESTAMO 2,6,'2024-11-30','2024-12-15', 1
GO
--SELECT*FROM [dbo].[PRESTAMO] WHERE idPrestamo = 8

/*Disparador o Trigger asociado a la tabla de Prestamos, y que ante el cambio en el estado delPréstamo 
a “Devuelto”, verifique si se encuentra en el plazo establecido, en caso contrario, deberá generar la 
multa respectiva. (10 pts).a.Cálculo de los datos de días y el monto de la multa. (5 pts)b.Registro de 
la multa en la tabla multas. (5 pt)*/

CREATE TRIGGER TR_GenerarMulta
ON PRESTAMO
AFTER UPDATE
AS
BEGIN
    SET NOCOUNT ON;

    -- Declaración de variables
    DECLARE @idPrestamo INT;
    DECLARE @FechaDevolucion DATE;
    DECLARE @FechaPrestamo DATE;
    DECLARE @CantidadDias INT;
    DECLARE @DiasAtraso INT;
    DECLARE @MontoDiario DECIMAL(10, 2) = 1.50; -- Monto diario de multa
    DECLARE @MontoTotal DECIMAL(10, 2);
    DECLARE @idLibro INT;

    -- Selección directa para manejar múltiples filas actualizadas
    SELECT 
        @idPrestamo = i.idPrestamo,
        @FechaDevolucion = i.FechaDevolucion,
        @FechaPrestamo = i.FechaPrestamo,
        @CantidadDias = l.CantidadDias,
        @idLibro = i.idLibro
    FROM inserted i
    INNER JOIN LIBRO l ON i.idLibro = l.idLibro
    WHERE i.FechaDevolucion IS NOT NULL;

    -- Calcula días de atraso y el monto de la multa
    IF @FechaDevolucion > DATEADD(DAY, @CantidadDias, @FechaPrestamo)
    BEGIN
        SET @DiasAtraso = DATEDIFF(DAY, DATEADD(DAY, @CantidadDias, @FechaPrestamo), @FechaDevolucion);
        SET @MontoTotal = @DiasAtraso * @MontoDiario;

        -- Inserta la multa si no existe
        IF NOT EXISTS (SELECT 1 FROM MULTA WHERE idPrestamo = @idPrestamo)
        BEGIN
            INSERT INTO MULTA (
                FechaGeneracion, 
                CantDiasAtraso, 
                MontoDiario, 
                MontoTotal, 
                Estado, 
                idPrestamo
            )
            VALUES (
                GETDATE(), 
                @DiasAtraso, 
                @MontoDiario, 
                @MontoTotal, 
                'Pendiente', 
                @idPrestamo
            );
        END;
    END;

    -- Marca el libro como disponible
    UPDATE LIBRO
    SET Disponibilidad = 1
    WHERE idLibro = @idLibro;
END
GO


--lo mas seguro tengo que cambiar las fechas 
/* UPDATE PRESTAMO
SET FechaDevolucion = '2024-12-05' -- Fecha posterior al plazo de 7 días desde 2024-11-25
WHERE idPrestamo = 1 */


