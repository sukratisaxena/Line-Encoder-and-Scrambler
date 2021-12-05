import './App.css';
import 'bootstrap/dist/css/bootstrap.min.css';
import Navbar from './components/Navbar';
import Footer from './components/Footer';
import Sometext from './components/Sometext'
function App() {
  return (
    <div className="App">
      <Navbar />
      <Sometext />
      <Footer />
    </div>
  )
}

export default App;
