describe('Search', () => {

  beforeEach(() => {
    cy.visit('https://petstore.octoperf.com/actions/Catalog.action')// Visita la página 
  })

  it('JPD-1: FE | Search | Búsqueda básica de productos', () => {
    cy.get('input[name="keyword"]');// Localiza el campo de búsqueda utilizando
    cy.get('input[name="keyword"]').type('Iguana');// Escribe la palabra 'Iguana' en el campo de búsqueda.
    cy.get('input[name="searchProducts"]').click();// Hace clic en el botón de búsqueda
    cy.screenshot();
  })

})