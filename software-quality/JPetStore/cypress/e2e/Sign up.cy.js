describe('Sign up', () => {

  beforeEach(() => {
    cy.visit('https://petstore.octoperf.com/actions/Catalog.action')// Visita la página 
  })

  it('JPD-3: FE | Sign up | Registro de usuario exitoso', () => {
    cy.contains('Sign In').click(); // Hace clic en el enlace "Sign In"
    cy.contains('Register Now!').click();// Hace clic en "Register Now!"
    cy.get('input[name="username"]').type('J1234'); // Ingresa un dato en el campo correspondiente , cambiar 
    cy.get('input[name="password"]').type('1234');
    cy.get('input[name="repeatedPassword"]').type('1234');
    cy.get('input[name="account.firstName"]').type('Juan');
    cy.get('input[name="account.lastName"]').type('Alvarado');
    cy.get('input[name="account.email"]').type('juan@example.com');
    cy.get('input[name="account.phone"]').type('8888 8888');
    cy.get('input[name="account.address1"]').type('Heredia');
    cy.get('input[name="account.address2"]').type('Santo Domingo');
    cy.get('input[name="account.city"]').type('Heredia');
    cy.get('input[name="account.state"]').type('Heredia');
    cy.get('input[name="account.zip"]').type('40101');
    cy.get('input[name="account.country"]').type('Costa Rica');
    cy.get('select[name="account.languagePreference"]').select('english');// Selecciona el idioma preferido
    cy.get('select[name="account.favouriteCategoryId"]').select('DOGS');// Selecciona la categoría de productos favorita
    cy.get('input[name="account.listOption"]').check(); // Marca la opción 
    cy.get('input[name="account.bannerOption"]').check(); // Marca la opción 
    cy.screenshot();
    cy.get('input[name="newAccount"]').click(); // Hace clic en el botón para crear la nueva cuenta
    
    
  })

})