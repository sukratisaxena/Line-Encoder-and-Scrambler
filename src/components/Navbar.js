import React, { Component } from 'react'
import {Navbar,Container,Nav,NavDropdown} from 'react-bootstrap'
export default class navbar extends Component {
    render() {
        return (
            <div>
              <div className="row mb-3">
              <div className="col-md-12">
               <Navbar bg="dark" variant={"dark"} expand="lg">
                <Container>
                  <Navbar.Brand href="#home"> Logo</Navbar.Brand>
                  <Navbar.Toggle aria-controls="basic-navbar-nav" />
                  <Navbar.Collapse id="basic-navbar-nav">
                    <Nav className="mx-auto">
                      <Nav.Link href="#">Home</Nav.Link>
                      <Nav.Link href="#">Link1</Nav.Link>
                      <Nav.Link href="#">Link2</Nav.Link>
                      <Nav.Link href="#">Link3</Nav.Link>
                      <NavDropdown title="Dropdown" class="d-flex text-items-center" id="basic-nav-dropdown">
                        <NavDropdown.Item href="#">Item1</NavDropdown.Item>
                        <NavDropdown.Item href="#">Item2</NavDropdown.Item>
                        <NavDropdown.Item href="#">Item3</NavDropdown.Item>
                        <NavDropdown.Divider />
                        <NavDropdown.Item href="#">Item4</NavDropdown.Item>
                        </NavDropdown>
                    </Nav>
                    <div class= "float-right">
                  <div class="input-group">
                    <div class="col-xs-3">    
                  <input type="text" class="form-control" placeholder="Search..." />
                  </div>
                  <div class="input-group-btn">
                      <button type="button" class="btn btn-light mx-2">Search</button> 
                  </div>
                  </div>
                  </div>
                  </Navbar.Collapse>
                </Container>
               </Navbar>
              </div>
            </div>
        </div>
        )
    }
}
