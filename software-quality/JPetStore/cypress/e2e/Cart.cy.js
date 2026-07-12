describe('Cart', () => {

  beforeEach(() => {
    cy.visit('https://petstore.octoperf.com/actions/Catalog.action');// Visita la página 
    cy.get('img[src="../images/fish_icon.gif"]').click();// Hace clic en el icono de peces
    cy.contains('FI-SW-01').click();// Selecciona el producto específico FI-SW-01
  })

  it('JPD-8: FE | Cart | Añadir productos al carrito', () => {
    cy.contains('Add to Cart').click();// Hace clic en el botón "Add to Cart"
    cy.contains('Shopping Cart').should('be.visible');// Verifica que el carrito de compras es visible
    cy.screenshot();
  })

  it('JPD-9: FE | Cart | Eliminar productos del carrito', () => {
    cy.contains('Add to Cart').click(); // Añade un producto al carrito
    cy.contains('Remove').click();// Hace clic en el botón "Remove"
    cy.contains('Your cart is empty').should('be.visible');// Verifica que el carrito está vacío
    cy.screenshot();
  })

})