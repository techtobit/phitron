import React, { useState } from 'react'
import { Link } from "react-router-dom";
import { useAppSelector } from './redux/TypeHoock';
import logo from './assets/hs.png'
import { AiOutlineWechat } from "react-icons/ai";
import { useDispatch, useSelector } from 'react-redux';
import { RootState } from './redux/Store';
import { setDashboardBtnActive } from './redux/dashboardSlice';
import { GrLanguage } from "react-icons/gr";


const NavBar: React.FC = () => {
  const dispatch = useDispatch()
  const dashboardBtnActive = useSelector((state: RootState) => state.dashboard.isActive)
  const authToken = useAppSelector((state) => state.auth.token)
  const [logInBtnActive, setLogInBtnActive] = useState(false)


  const handleDashboardBtn = () => {
    dispatch(setDashboardBtnActive(false))
  }





  return (
    <nav className="bg-white border-b-[1px] border-gray-100 border-gray-200 dark:bg-gray-900">
      <div className="max-w-screen-xl flex flex-wrap items-center justify-between mx-auto p-4">
        <a href="/" className="flex items-center space-x-3 rtl:space-x-reverse">
          <img src={logo} className="h-8" alt="Flowbite Logo" />
          <span className="self-center text-2xl font-semibold whitespace-nowrap dark:text-white">Household</span>
        </a>
        <button data-collapse-toggle="navbar-default" type="button" className="inline-flex items-center p-2 w-10 h-10 justify-center text-sm text-gray-500 rounded-lg md:hidden hover:bg-gray-100 focus:outline-none focus:ring-2 focus:ring-gray-200 dark:text-gray-400 dark:hover:bg-gray-700 dark:focus:ring-gray-600" aria-controls="navbar-default" aria-expanded="false">
          <span className="sr-only">Open main menu</span>
          <svg className="w-5 h-5" aria-hidden="true" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 17 14">
            <path stroke="currentColor" stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M1 1h15M1 7h15M1 13h15" />
          </svg>
        </button>
        <ul className="font-medium flex flex-col p-4 md:p-0 mt-4 border border-gray-100 rounded-lg bg-gray-50 md:flex-row md:space-x-8 rtl:space-x-reverse md:mt-0 md:border-0 md:bg-white dark:bg-gray-800 md:dark:bg-gray-900 dark:border-gray-700">
          <li>
            <Link to="/"
              className="block py-2 px-3 text-gray-900 rounded hover:bg-gray-100 md:hover:bg-transparent md:border-0 md:hover:text-blue-700 md:p-0 dark:text-white md:dark:hover:text-blue-500 dark:hover:bg-gray-700 dark:hover:text-white md:dark:hover:bg-transparent"
            >Home</Link>
          </li>
          <li>
            <Link to="services/"
              className="block py-2 px-3 text-gray-900 rounded hover:bg-gray-100 md:hover:bg-transparent md:border-0 md:hover:text-blue-700 md:p-0 dark:text-white md:dark:hover:text-blue-500 dark:hover:bg-gray-700 dark:hover:text-white md:dark:hover:bg-transparent"
            >Find Services</Link>
          </li>
          <li>
            <Link to="api_endpoints/"
              className="block py-2 px-3 text-gray-900 rounded hover:bg-gray-100 md:hover:bg-transparent md:border-0 md:hover:text-blue-700 md:p-0 dark:text-white md:dark:hover:text-blue-500 dark:hover:bg-gray-700 dark:hover:text-white md:dark:hover:bg-transparent"
            >Test API Endpoints</Link>
          </li>
          <li>
            <Link to="services/"
              className="block py-2 px-3 text-gray-900 rounded hover:bg-gray-100 md:hover:bg-transparent md:border-0 md:hover:text-blue-700 md:p-0 dark:text-white md:dark:hover:text-blue-500 dark:hover:bg-gray-700 dark:hover:text-white md:dark:hover:bg-transparent"
            >Find Client</Link>
          </li>
          <li>
            <Link to="services/"
              className="block py-2 px-3 text-gray-900 rounded hover:bg-gray-100 md:hover:bg-transparent md:border-0 md:hover:text-blue-700 md:p-0 dark:text-white md:dark:hover:text-blue-500 dark:hover:bg-gray-700 dark:hover:text-white md:dark:hover:bg-transparent"
            >Subscription</Link>
          </li>
          <li>
            <Link to="services/"
              className="block py-2 px-3 text-gray-900 rounded hover:bg-gray-100 md:hover:bg-transparent md:border-0 md:hover:text-blue-700 md:p-0 dark:text-white md:dark:hover:text-blue-500 dark:hover:bg-gray-700 dark:hover:text-white md:dark:hover:bg-transparent"
            >Feedback</Link>
          </li>
        </ul>
        <div className="hidden w-full md:block md:w-auto" id="navbar-default">
          <ul className="font-medium flex flex-col p-4 md:p-0 mt-4 border border-gray-100 rounded-lg bg-gray-50 md:flex-row md:space-x-8 rtl:space-x-reverse md:mt-0 md:border-0 md:bg-white dark:bg-gray-800 md:dark:bg-gray-900 dark:border-gray-700">
            <li>
              <Link to="services/"
                className="block flex items-center gap-[2px] py-2 px-3 text-gray-900 rounded hover:bg-gray-100 md:hover:bg-transparent md:border-0 md:hover:text-blue-700 md:p-0 dark:text-white md:dark:hover:text-blue-500 dark:hover:bg-gray-700 dark:hover:text-white md:dark:hover:bg-transparent"
              > <GrLanguage /> English</Link>
            </li>


            {
              authToken ?
                <>
                  {!(dashboardBtnActive) ?
                    <li>
                      <Link className='flex items-center gap-2' to='/user/dashboard/'><AiOutlineWechat /> Support Ticket</Link>
                    </li>
                    :
                    <li>
                      <Link onClick={handleDashboardBtn} to='/user/dashboard/'>Dashboard</Link>
                    </li>

                  }
                </>
                :
                <>
                  {logInBtnActive ?

                    <li>
                      <Link to="/user/login/"
                        type='button'
                        onClick={() => setLogInBtnActive(false)}
                        className="focus:outline-none text-white bg-yellow-400 hover:bg-yellow-500 focus:ring-4 focus:ring-yellow-300 font-medium rounded-lg text-sm px-5 py-2.5 me-2 mb-2 dark:focus:ring-yellow-900"
                      >Login</Link>
                    </li>
                    :

                    <li>
                      <Link to="/user/create/buyer_register/"
                        type='button'
                        onClick={() => setLogInBtnActive(true)}
                        className="focus:outline-none text-white bg-yellow-400 hover:bg-yellow-500 focus:ring-4 focus:ring-yellow-300 font-medium rounded-lg text-sm px-5 py-2.5 me-2 mb-2 dark:focus:ring-yellow-900"
                      >Create Account</Link>
                    </li>
                  }
                </>
            }

          </ul>
        </div>
      </div>
    </nav>

  )
}

export default NavBar;
