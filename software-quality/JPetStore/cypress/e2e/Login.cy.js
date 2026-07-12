describe('Login', () => {

  beforeEach(() => {
    cy.visit('https://petstore.octoperf.com/actions/Catalog.action');// Visita la página 
    cy.contains('Sign In').click(); // Hace clic en el enlace "Sign In"
    cy.get('input[name="username"]').type('Juan Pablo');// Rellena el campo de usuario
    cy.get('input[name="password"]').clear(); // Limpia el campo de contraseña
    cy.get('input[name="password"]').type('1234');// Rellena el campo de contraseña
  })

  it('JPD-5: FE | Login | Inicio de sesión exitoso', () => {    
    cy.get('input[name="signon"]').click();// Hace clic en el botón "signon" 
    cy.contains('Welcome Juan!').should('be.visible');// Verifica que el mensaje de bienvenida 
    cy.screenshot();
  })


  it('JPD-13: FE | Login | Cierre de sesión ', () => {
    cy.get('input[name="signon"]').click();
    cy.contains('Sign Out').click();// Hace clic en el enlace "Sign Out
    cy.contains('Sign In').should('be.visible');// Verifica que el enlace "Sign In" aparece nuevamente en la página
    cy.screenshot();
  })

})