import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import App from './App.tsx'
import './index.css'
// import { AuthProvider } from './auth/AuthProvider.tsx'
import { Provider } from 'react-redux'
import store from './redux/Store.ts'


createRoot(document.getElementById('root')!).render(
    <StrictMode>
      <Provider store={store}>
        <App />
      </Provider>
    </StrictMode>,

)
