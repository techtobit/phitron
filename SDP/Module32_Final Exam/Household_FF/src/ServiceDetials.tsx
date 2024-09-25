import axios from 'axios'
import React, { useEffect, useState } from 'react'
import { Link, useParams } from 'react-router-dom';
import { FaUser } from "react-icons/fa6";
import { IoLogoUsd } from "react-icons/io5";
import { ImPriceTags } from "react-icons/im";
import { FaCartPlus } from "react-icons/fa";
import { RiShoppingBag4Fill } from "react-icons/ri";
import StarRate from './utils/Rating';
import { useDispatch } from 'react-redux';
import { setDashboardAsideBtn } from './redux/dashboardSlice';
import toast from 'react-hot-toast';
import { AiFillLinkedin, AiFillYoutube, AiFillGithub, AiOutlineGlobal } from "react-icons/ai";


interface ServicesDetailsState {
	id: number,
	seller: number,
	service_title: string,
	categories: any,
	price: number,
	image: any,
	discription: string,
}

interface SellerState {
	user: string;
	service_category: string,
	phone: string,
	completed_jobs: number
}

interface ServiceReview {
	"rating": number,
	"body": string,
	"service": number,
}


const ServiceDetials: React.FC = () => {

	const { id } = useParams()
	const [service, setService] = useState<ServicesDetailsState | null>(null)
	const [servicesSeller, setServicesSeller] = useState<SellerState | null>(null)
	const [servicesReview, setServicesReview] = useState<ServiceReview[]>([])
	const dispatch = useDispatch()

	const username = `${service?.seller}`

	const handelRedirectCart = (clickedCompo: string) => {
		dispatch(setDashboardAsideBtn(clickedCompo))
		// navigate('')

	}

	useEffect(() => {
		const fetchServices = async () => {
			try {
				const response = await axios.get(`https://household-backend-a4k7.onrender.com/services/list/${id}/`)
				setService(response.data)
			} catch (error) {
				console.error(error)
			}
		}
		fetchServices()
	}, [])


	// Adding userId and ServiceId into Cart Model 
	const cartData = {
		"customer": service?.seller,
		"service": service?.id,
		"category": service?.categories.category,
		"price": service?.price,
	}

	const addToCartService = async () => {
		console.log('cartData', cartData);

		try {
			const response = await axios.post(`https://household-backend-a4k7.onrender.com/orders/cart/`, cartData, {
				headers: {
					"Content-Type": "application/json"
				}
			})
			if (!response) {
				toast.error('Faild to add cart')
			}
			else {
				toast.success('succesfully added to cart list')
			}
			console.log("cart - response -", response);

		} catch (error) {
			toast.error(`Faild to add cart ${error}`)
			console.error(error)
		}
	}


	// fetch and get service reviews
	useEffect(() => {
		const fetchServicesSeller = async () => {
			try {
				const response = await axios.get(`https://household-backend-a4k7.onrender.com/auth/seller_profile/?username=${username}`)
				setServicesSeller(response.data[0])
			} catch (error) {
				console.error(error)
			}
		}
		fetchServicesSeller()
	}, [username])


	useEffect(() => {
		const fetchReview = async () => {
			try {
				const response = await axios.get(`https://household-backend-a4k7.onrender.com/services/review/?service=${id}`)
				setServicesReview(response.data)
				console.log('Review List-', response.data);

			} catch (error) {
				console.error(error)
			}
		}
		fetchReview()
	}, [servicesReview])


	const handelSubmitReviw = (event:any)=>{
		event.preventDefault();
		const rating= event.target.rating.value;
		const body = event.target.body.value;
		const serviceId = event.target.serviceId.value;

		const reviewData={
			service: serviceId,
			rating: rating,
			body : body
		}

		try {
			const response =axios.post(`https://household-backend-a4k7.onrender.com/services/review/`, reviewData, {
				headers: {
					"Content-Type": "application/json"
				}
			})
			if (!response) {
				toast.error('Faild to give review')
			}
			else {
				toast.success('Thanks for giving review')
				event.target.rating.value=''
				event.target.body.value=''
				
			}
			console.log("review - response -", response);

		} catch (error) {
			toast.error(`Faild to submit review | Error- ${error}`)
			console.error(error)
		}
		
		
	}

	return (
		<div className='grid grid-cols-3 gap-10 p-10'>
			<div className='col-span-2'>

				<div className=" w-full p-6 bg-white border border-gray-200 rounded-lg shadow dark:bg-gray-800 dark:border-gray-700">
					<div className="font-sans rounded-md ">
						<img src={service?.image} alt="Banner Image" className=" rounded-md inset-0 w-full h-96 object-cover" />
					</div>
					<a href="#">
						<h5 className="pt-6 mb-2 text-2xl font-bold tracking-tight text-gray-900 dark:text-white">{service?.service_title}</h5>
					</a>
					<div className="flex gap-2 mb-1 font-normal text-gray-700 dark:text-gray-400">
						<p className="flex items-center gap-2 py-[2px] px-2 me-2 mb-2 text-sm font-medium text-gray-900 focus:outline-none bg-white rounded-full border border-gray-200 hover:bg-gray-100 hover:text-blue-700 focus:z-10 focus:ring-4 focus:ring-gray-100 dark:focus:ring-gray-700 dark:bg-gray-800 dark:text-gray-400 dark:border-gray-600 dark:hover:text-white dark:hover:bg-gray-700"><FaUser />{service?.seller}</p>
						<p className="flex items-center gap-2 py-[2px] px-2 me-2 mb-2 text-sm font-medium text-gray-900 focus:outline-none bg-white rounded-full border border-gray-200 hover:bg-gray-100 hover:text-blue-700 focus:z-10 focus:ring-4 focus:ring-gray-100 dark:focus:ring-gray-700 dark:bg-gray-800 dark:text-gray-400 dark:border-gray-600 dark:hover:text-white dark:hover:bg-gray-700"><IoLogoUsd />{service?.price}</p>
						<p className="flex items-center gap-2 py-[2px] px-2 me-2 mb-2 text-sm font-medium text-gray-900 focus:outline-none bg-white rounded-full border border-gray-200 hover:bg-gray-100 hover:text-blue-700 focus:z-10 focus:ring-4 focus:ring-gray-100 dark:focus:ring-gray-700 dark:bg-gray-800 dark:text-gray-400 dark:border-gray-600 dark:hover:text-white dark:hover:bg-gray-700"><ImPriceTags />{service?.categories?.category}</p>
					</div>

					<p className="mb-3 font-normal text-gray-700 dark:text-gray-400">{service?.discription}</p>

					<button onClick={addToCartService} className=" flex gap-2 items-center inline-flex items-center px-3 py-2 text-sm font-medium text-center text-white bg-blue-700 rounded-lg hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">
						Add Cart <FaCartPlus />
					</button>
					<Link to='/user/dashboard/' onClick={() => handelRedirectCart('carts')} className=" flex gap-2 items-center ml-2 inline-flex items-center px-3 py-2 text-sm font-medium text-center text-white bg-blue-700 rounded-lg hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">
						Check Carts <RiShoppingBag4Fill />
					</Link>
				</div>

				<div className='w-full my-10 p-5 bg-white border border-gray-200 rounded-lg shadow dark:bg-gray-800 dark:border-gray-700'>
					<h1 className='text-xl font-medium pb-4 underline'>Add Review & Feedback about service</h1>
					<form onSubmit={handelSubmitReviw} className="">
						<label htmlFor="rating" className="block mb-2 text-sm font-medium text-gray-900 dark:text-white">Select an rating</label>
						<select id="rating" required className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500">
							<option selected>Choose a Rate</option>
							<option value={5}>⭐⭐⭐⭐⭐</option>
							<option value={4}>⭐⭐⭐⭐</option>
							<option value={3}>⭐⭐⭐</option>
							<option value={2}>⭐⭐</option>
							<option value={1}>⭐</option>
						</select>
						<input id='serviceId' type="number" value={service?.id} hidden />
						<label htmlFor="body" className="block my-2 text-sm font-medium text-gray-900 dark:text-white">Your message</label>
						<textarea id="body" required  className="block p-2.5 w-full text-sm text-gray-900 bg-gray-50 rounded-lg border border-gray-300 focus:ring-blue-500 focus:border-blue-500 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="Write your thoughts here..."></textarea>
						<button type="submit" className="my-2 text-white bg-blue-700 hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 font-medium rounded-lg text-sm w-full sm:w-auto px-5 py-2.5 text-center dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">Submit</button>
					</form>

				</div>

				<div className=" w-full mt-10 p-6 bg-white borderborder-gray-200 rounded-lg shadow dark:bg-gray-800 dark:border-gray-700">
					{
						servicesReview?.map((review, idx) => (

							<article key={idx} className=' '>
								<div className="flex items-center mb-4  ">
									<img className="w-10 h-10 me-4 rounded-full" src="https://images.unsplash.com/photo-1535713875002-d1d0cf377fde?ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=2000&q=80" alt="" />
									<div className="font-medium dark:text-white">
										<p>Jese Leos <time dateTime="2014-08-16 19:00" className="block text-sm text-gray-500 dark:text-gray-400">Joined on August 2014</time></p>
									</div>
								</div>
								<div className="flex items-center mb-1 space-x-1 rtl:space-x-reverse">
									<StarRate rating={review.rating || 0} />
									<h3 className="ms-2 text-sm font-semibold text-gray-900 dark:text-white">Thinking to buy another one!</h3>
								</div>
								<footer className="mb-5 text-sm text-gray-500 dark:text-gray-400"><p>Reviewed in the United Kingdom on <time dateTime="2017-03-03 19:00">March 3, 2017</time></p></footer>
								<p className="mb-2 text-gray-500 dark:text-gray-400">{review?.body}</p>
								<a href="#" className="block mb-5 text-sm font-medium text-blue-600 hover:underline dark:text-blue-500">Read more</a>
								<aside>
									<p className="mt-1 text-xs text-gray-500 dark:text-gray-400">19 people found this helpful</p>
									<div className="flex items-center mt-3">
										<a href="#" className="px-2 py-1.5 text-xs font-medium text-gray-900 focus:outline-none bg-white rounded-lg border border-gray-200 hover:bg-gray-100 hover:text-blue-700 focus:z-10 focus:ring-4 focus:ring-gray-100 dark:focus:ring-gray-700 dark:bg-gray-800 dark:text-gray-400 dark:border-gray-600 dark:hover:text-white dark:hover:bg-gray-700">Helpful</a>
										<a href="#" className="ps-4 text-sm font-medium text-blue-600 hover:underline dark:text-blue-500 border-gray-200 ms-4 border-s md:mb-0 dark:border-gray-600">Report abuse</a>
									</div>
								</aside>
								<hr className='my-5' />
							</article>

						))
					}

				</div>

			</div>

			<div className="w-full justify-center items-center h-screen">
				<div className="max-w-[490px] rounded-lg w-[100%] overflow-hidden bg-white shadow-[0_0_1rem_rgba(0,0,0,0.2)] ">
					<div className="card">
						<div className="grid grid-cols-5">
							<div className="col-span-2 p-3">
								<img src="https://svgshare.com/i/16D0.svg" alt="demo" />
							</div>
							<div className="col-span-3 p-3">
								<div className="font-bold uppercase">{servicesSeller?.user}</div>
								<div className="mb-3">Senior {servicesSeller?.service_category}</div>
								<div
									className="card flex justify-between items-center text-gray-500 bg-gray-200 focus:bg-white rounded-lg p-2">
									<div className="text-center">
										<p className="text-sm">In Queue</p>
										<p className="font-bold text-gray-800">10+</p>
									</div>
									<div className="text-center">
										<p className="text-sm">Done</p>
										<p className="font-bold text-gray-800">{servicesSeller?.completed_jobs}</p>
									</div>
									<div className="text-center">
										<p className="text-sm">Rating</p>
										<p className="font-bold text-gray-800 flex gap-1">
											<img src="https://svgshare.com/i/16Fg.svg" />
											4.5
										</p>
									</div>
								</div>
								<div className="flex mt-3 gap-2">
									<button className="bg-white text-gray-500 py-2 px-4 rounded-lg border-2 hover:bg-gray-400 flex-1">
										Chat
									</button>
									<button className="bg-blue-500 text-white py-2 px-4 rounded-lg hover:bg-blue-700 flex-1">
										Follow
									</button>


								</div>
								<div className='flex gap-4 pt-2'>
									<a href="https://www.linkedin.com/in/ashrafuddin17/" target='_blank'>
										<AiFillLinkedin className='w-10 h-10 p-2 rounded-lg bg-gray-100 hover:bg-gray-300' />
									</a>
									<a href="https://ashrafuddin.vercel.app/" target='_blank'>
										<AiFillYoutube className='w-10 h-10 p-2 rounded-lg bg-gray-100 hover:bg-gray-300' />
									</a>
									<a href="https://ashrafuddin.vercel.app/" target='_blank'>
										<AiOutlineGlobal className='w-10 h-10 p-2 rounded-lg bg-gray-100 hover:bg-gray-300' />
									</a>
									<a href="https://github.com/techtobit" target='_blank'>
										<AiFillGithub className='w-10 h-10 p-2 rounded-lg bg-gray-100 hover:bg-gray-300' />
									</a>
								</div>
							</div>
						</div>
					</div>
				</div>
			</div>

			{/* <div className="w-full max-w-sm bg-white border border-gray-200 rounded-lg shadow dark:bg-gray-800 dark:border-gray-700">
				<div className="flex flex-col items-center pb-10">
					<img className="w-24 h-24 mb-3 rounded-full shadow-lg" src="/docs/images/people/profile-picture-3.jpg" alt="Bonnie image" />
					<h5 className="mb-1 text-xl font-medium text-gray-900 dark:text-white">{servicesSeller?.user}</h5>
					<p className="flex gap-2 items-center text-sm text-gray-500 dark:text-gray-400">Category <MdCategory /> {servicesSeller?.service_category}</p>
					<p className="flex gap-2 items-center text-sm text-gray-500 dark:text-gray-400">Phone <FaPhoneSquareAlt /> {servicesSeller?.phone}</p>
					<p className="flex gap-2 items-center  text-sm text-gray-500 dark:text-gray-400">Completed Jobs <BiTask /> {servicesSeller?.completed_jobs}</p>
					<div className="flex mt-4 md:mt-6">
						<a href="#" className="inline-flex items-center px-4 py-2 text-sm font-medium text-center text-white bg-blue-700 rounded-lg hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">Bookmark</a>
						<a href="#" className="py-2 px-4 ms-2 text-sm font-medium text-gray-900 focus:outline-none bg-white rounded-lg border border-gray-200 hover:bg-gray-100 hover:text-blue-700 focus:z-10 focus:ring-4 focus:ring-gray-100 dark:focus:ring-gray-700 dark:bg-gray-800 dark:text-gray-400 dark:border-gray-600 dark:hover:text-white dark:hover:bg-gray-700">Message</a>
					</div>
				</div>
			</div> */}

		</div>
	)
}

export default ServiceDetials