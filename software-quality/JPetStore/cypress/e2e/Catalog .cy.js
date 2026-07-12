describe('Catalog', () => {

  beforeEach(() => {
    cy.visit('https://petstore.octoperf.com/actions/Catalog.action')// Visita la página 
  })
  
  it('JPD-2: FE | Catalog | Navegar por el catálogo', () => {
    cy.get('img[src="../images/fish_icon.gif"]').click();// Hace clic en el icono de la categoria
    cy.contains('Return to Main Menu').click();// Hace clic en "Return to Main Menu"
    cy.get('img[src="../images/dogs_icon.gif"]').click();
    cy.contains('Return to Main Menu').click();
    cy.get('img[src="../images/cats_icon.gif"]').click();
    cy.contains('Return to Main Menu').click();
    cy.get('img[src="../images/reptiles_icon.gif"]').click();
    cy.contains('Return to Main Menu').click();
    cy.get('img[src="../images/birds_icon.gif"]').click();
    cy.contains('Return to Main Menu').click();
    cy.screenshot();
  })

})