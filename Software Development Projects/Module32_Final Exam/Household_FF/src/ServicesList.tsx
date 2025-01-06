import axios from 'axios'
import React, { useEffect, useState } from 'react'
import { FaUser } from "react-icons/fa6";
import { IoLogoUsd } from "react-icons/io5";
import { ImPriceTags } from "react-icons/im";
import { Link } from 'react-router-dom';

interface CategorySlugState {
	category: string,
	slug: string
}

interface ServicesListState {
	id: number,
	seller: number;
	service_title: string,
	categories: any,
	price: number
	image: string,
	discription: string,
}


const Services: React.FC = () => {
	const [servicesList, setServicesList] = useState<ServicesListState[]>([])
	const [categorySlug, setCategorySlug] = useState<CategorySlugState[]>([])
	const [selectCategory, setSelectCategory] = useState(null)
	const [selectRating, setSelectRating] = useState(null)
	const [restFilter, setResetFilter]= useState(false)

	useEffect(() => {
		const fetchServices = async () => {
			try {
				const response = await axios.get('https://household-backend-a4k7.onrender.com/services/list/')
				setServicesList(response.data)

			} catch (error) {
				console.error(error)
			}
		}
		fetchServices()
	}, [restFilter])

	console.log('serviceList-', servicesList);


	useEffect(() => {
		const fetchCategories = async () => {
			try {
				const response = await axios.get('https://household-backend-a4k7.onrender.com/services/categories/')
				setCategorySlug(response.data)
			} catch (error) {
				console.error(error)
			}
		}
		fetchCategories()
	}, [])



	const fetchFilteredCategory = async (categoryName: any, rating: any) => {
		try {
			const response = await axios.get(`https://household-backend-a4k7.onrender.com/services/list/category/${categoryName}/`, {
				params:{
					avg_rating: rating,
				}
			})
			setServicesList(response.data)
		} catch (error) {
			console.error(error)
		}
	}


	////select and get category wise data
	const handelChangeCategory = (categoryName: any) => {
		setSelectCategory(categoryName)
		fetchFilteredCategory(categoryName, selectRating)
	}

	function handelChangeRating(rating: any) {
		setSelectRating(rating)
		fetchFilteredCategory(selectCategory, rating)
		
	}

	const handleResetFilter= ()=> {
		setResetFilter(!restFilter)
		setSelectCategory(null)
		setSelectRating(null)
	}


	const ratings : Record<number, string>= {
		1: '⭐',
		2: '⭐⭐',
		3: '⭐⭐⭐',
		4: '⭐⭐⭐⭐',
		5: '⭐⭐⭐⭐⭐'
	};




	return (
		<div className='flex gap-10  '>
			<div className="relative flex flex-col text-gray-700 bg-gray-50 shadow-md w-1/4 rounded-xl bg-clip-border">
				<nav className=" sticky top-20 flex min-w-[240px] flex-col gap-1 p-2 font-sans text-base font-normal text-blue-gray-700">
					<h2 className='font-bold pl-2 underline pb-2'>Filter by category</h2>
					{
						categorySlug?.map((slug, idx: number) => (
							<div key={idx} onChange={() => handelChangeCategory(slug?.category)} className="flex items-center ps-4 border border-gray-200 rounded dark:border-gray-700">
								<input id="bordered-checkbox-2" type="checkbox" checked={selectCategory == slug?.category} value={slug?.category} name="bordered-checkbox" className="w-4 h-4 text-blue-600 bg-gray-100 border-gray-300 rounded focus:ring-blue-500 dark:focus:ring-blue-600 dark:ring-offset-gray-800 focus:ring-2 dark:bg-gray-700 dark:border-gray-600" />
								<label htmlFor="bordered-checkbox-2" className="w-full capitalize py-2 ms-2 text-sm font-medium text-gray-900 dark:text-gray-300">	{slug?.category}</label>
							</div>
						))}

					<h2 className='font-bold pl-2 underline py-2'>Filter by rateing</h2>
						{
							[5, 4, 3, 2, 1].map((rating, idx) => (
								<div key={idx} onChange={()=> handelChangeRating(rating)} className="flex gap-2 items-center ps-4 border border-gray-200 rounded dark:border-gray-700">
								<input id="bordered-checkbox-2" type="checkbox" checked={selectRating=== rating}   name="bordered-checkbox" className="w-4 h-4 text-blue-600 bg-gray-100 border-gray-300 rounded focus:ring-blue-500 dark:focus:ring-blue-600 dark:ring-offset-gray-800 focus:ring-2 dark:bg-gray-700 dark:border-gray-600" />
								<label htmlFor="bordered-checkbox-2" className="w-full py-2 ms-2 text-sm font-medium text-gray-900 dark:text-gray-300">  {ratings[rating]} ({rating})</label>
							</div>
							))
						}

<button onClick={handleResetFilter} type="submit" className="w-full mt-2 text-white bg-blue-700 hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 font-medium rounded-lg text-sm  px-5 py-2.5 text-center dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">Reset Filter</button>

				</nav>
			</div>

			<div className='flex flex-wrap  justify-around  w-full'>


				{
					servicesList.map((service, idx: number) => (
						<div key={idx} className="flex justify-center items-center min-h-screen">
							<div className="max-w-[720px] mx-auto ">

								{/* <!-- Centering wrapper --> */}
								<div className="relative  h-[80vh] flex w-full max-w-[26rem] flex-col rounded-xl bg-white bg-clip-border text-gray-700 shadow-lg">
									<div
										className="relative h-[30vh] mx-4 mt-4 overflow-hidden text-white shadow-lg rounded-xl bg-blue-gray-500 bg-clip-border shadow-blue-gray-500/40">
										<img
											src={service?.image}
											alt="ui/ux review check" />
										<div
											className="absolute inset-0 w-full h-full to-bg-black-10 bg-gradient-to-tr from-transparent via-transparent to-black/60">
										</div>
										<button
											className="!absolute top-4 right-4 h-8 max-h-[32px] w-8 max-w-[32px] select-none rounded-full text-center align-middle font-sans text-xs font-medium uppercase text-red-500 transition-all hover:bg-red-500/10 active:bg-red-500/30 disabled:pointer-events-none disabled:opacity-50 disabled:shadow-none"
											type="button">
											<span className="absolute transform -translate-x-1/2 -translate-y-1/2 top-1/2 left-1/2">
												<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="currentColor"
													className="w-6 h-6">
													<path
														d="M11.645 20.91l-.007-.003-.022-.012a15.247 15.247 0 01-.383-.218 25.18 25.18 0 01-4.244-3.17C4.688 15.36 2.25 12.174 2.25 8.25 2.25 5.322 4.714 3 7.688 3A5.5 5.5 0 0112 5.052 5.5 5.5 0 0116.313 3c2.973 0 5.437 2.322 5.437 5.25 0 3.925-2.438 7.111-4.739 9.256a25.175 25.175 0 01-4.244 3.17 15.247 15.247 0 01-.383.219l-.022.012-.007.004-.003.001a.752.752 0 01-.704 0l-.003-.001z">
													</path>
												</svg>
											</span>
										</button>
									</div>
									<div className="p-6">
										<div className="flex items-center justify-between mb-3">
											<h5 className="block font-sans text-xl antialiased font-medium leading-snug tracking-normal text-blue-gray-900">
												{service.service_title}
											</h5>
											<p
												className="flex items-center gap-1.5 font-sans text-base font-normal leading-relaxed text-blue-gray-900 antialiased">
												<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="currentColor"
													className="-mt-0.5 h-5 w-5 text-yellow-700">
													<path fill-rule="evenodd"
														d="M10.788 3.21c.448-1.077 1.976-1.077 2.424 0l2.082 5.007 5.404.433c1.164.093 1.636 1.545.749 2.305l-4.117 3.527 1.257 5.273c.271 1.136-.964 2.033-1.96 1.425L12 18.354 7.373 21.18c-.996.608-2.231-.29-1.96-1.425l1.257-5.273-4.117-3.527c-.887-.76-.415-2.212.749-2.305l5.404-.433 2.082-5.006z"
														clip-rule="evenodd"></path>
												</svg>
												5.0
											</p>
										</div>
										<div className="flex flex-wrap gap-[4px] mb-1 font-normal text-gray-700 dark:text-gray-400">
											<p className="flex items-center gap-[4px] py-[2px] px-2 me-2 mb-2 text-sm font-medium text-gray-900 focus:outline-none bg-white rounded-full border border-gray-200 hover:bg-gray-100 hover:text-blue-700 focus:z-10 focus:ring-4 focus:ring-gray-100 dark:focus:ring-gray-700 dark:bg-gray-800 dark:text-gray-400 dark:border-gray-600 dark:hover:text-white dark:hover:bg-gray-700"><FaUser />{service.seller}</p>
											<p className="flex items-center gap-[4px] py-[2px] px-2 me-2 mb-2 text-sm font-medium text-gray-900 focus:outline-none bg-white rounded-full border border-gray-200 hover:bg-gray-100 hover:text-blue-700 focus:z-10 focus:ring-4 focus:ring-gray-100 dark:focus:ring-gray-700 dark:bg-gray-800 dark:text-gray-400 dark:border-gray-600 dark:hover:text-white dark:hover:bg-gray-700"><IoLogoUsd />{service.price}</p>
											<p className="flex items-center gap-[4px] py-[2px] px-2 me-2 mb-2 text-sm font-medium text-gray-900 focus:outline-none bg-white rounded-full border border-gray-200 hover:bg-gray-100 hover:text-blue-700 focus:z-10 focus:ring-4 focus:ring-gray-100 dark:focus:ring-gray-700 dark:bg-gray-800 dark:text-gray-400 dark:border-gray-600 dark:hover:text-white dark:hover:bg-gray-700"><ImPriceTags />{service?.categories?.category}</p>
											<>

												{/* {service?.categories?.map(cat => (
													<p className="flex items-center gap-[4px] py-[2px] px-2 me-2 mb-2 text-sm font-medium text-gray-900 focus:outline-none bg-white rounded-full border border-gray-200 hover:bg-gray-100 hover:text-blue-700 focus:z-10 focus:ring-4 focus:ring-gray-100 dark:focus:ring-gray-700 dark:bg-gray-800 dark:text-gray-400 dark:border-gray-600 dark:hover:text-white dark:hover:bg-gray-700"><ImPriceTags />{cat?.category}</p>

												))} */}
											</>
										</div>
										<p className="block h-20 overflow-hidden font-sans text-base antialiased font-light leading-relaxed text-gray-700">
											{service.discription}
										</p>
									</div>
									<div className="p-6 absolute top-[65vh] block w-full">
										<Link to={`/services/${service.id}/`}
											className="block w-full select-none rounded-lg bg-gray-900 py-3.5 px-7 text-center align-middle font-sans text-sm font-bold uppercase text-white shadow-md shadow-gray-900/10 transition-all hover:shadow-lg hover:shadow-gray-900/20 focus:opacity-[0.85] focus:shadow-none active:opacity-[0.85] active:shadow-none disabled:pointer-events-none disabled:opacity-50 disabled:shadow-none"
											type="button">
											View Details
										</Link>
									</div>
								</div>
							</div>
						</div>
					))
				}

				{
					(servicesList.length ==0) && (
						<h1 className='flex items-center text-4xl'>Data Not Avaliable</h1>
					)
				}

			</div>
		</div>

	)
}

export default Services