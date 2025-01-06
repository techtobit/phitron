import React from 'react'
import HeroBanner from './HeroBanner'
import Footer from './Footer';
import AppLinks from './AppLinks';
import Story from './Story';


const HomeOutlet:React.FC=()=> {
	return (
		<>
		<HeroBanner/>
		<Story/>
		<AppLinks/>
		<Footer/>
		</>
	)
}

export default HomeOutlet;